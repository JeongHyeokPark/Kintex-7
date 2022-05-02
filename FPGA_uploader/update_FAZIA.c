#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   
#include <termios.h> 
#include <unistd.h>  
#include <errno.h>   

int FAZIA_open(char *device_name);
void FAZIA_close(int fd);
int FAZIA_protect(int fd);
int FAZIA_unprotect(int fd);
int FAZIA_status(int fd);
int FAZIA_erase(int fd, int sector);
int FAZIA_write(int fd, int sector, int page, unsigned char *data);
void FAZIA_read(int fd, int sector, int page, unsigned char *data);
int FAZIA_merge(char *filename_a, char *filename_b, unsigned char *data);

int FAZIA_open(char *device_name)
{
	int fd;
	struct termios SerialPortSettings;

	// open serial port
	fd = open(device_name, O_RDWR | O_NOCTTY);

	if(fd < 0) {
		printf("Fail to open serial port!\n");
		return -1;
	}

	printf("Serial port is open.\n");

	// set serial port
	tcgetattr(fd, &SerialPortSettings);
	cfsetispeed(&SerialPortSettings,B115200);	// baud rate = 115200
	cfsetospeed(&SerialPortSettings,B115200);
	SerialPortSettings.c_cflag &= ~PARENB;   	// disable parity
	SerialPortSettings.c_cflag &= ~CSTOPB;   	// stop bit = 1
	SerialPortSettings.c_cflag &= ~CSIZE;	 
	SerialPortSettings.c_cflag |=  CS8;    	// data size = 8 bit
	SerialPortSettings.c_cflag &= ~CRTSCTS;
	SerialPortSettings.c_cflag |= CREAD | CLOCAL; 
	SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY); 
	SerialPortSettings.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	SerialPortSettings.c_oflag &= ~OPOST;
	SerialPortSettings.c_cc[VMIN] = 1; 		// Read at least 1 characters
	SerialPortSettings.c_cc[VTIME] = 0; 		// wait Rx infinitely


	if((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0) 
		printf("ERROR ! in Setting attributes\n");
	else
		printf("BaudRate = 115200 \nStopBits = 1 \nParity   = none\n");

	// flush Rx data
	tcflush(fd, TCIFLUSH);

	return fd;
}

void FAZIA_close(int fd)
{
	close(fd);
}

int FAZIA_protect(int fd)
{
	int resp;
	unsigned char uart[2];
	int status;

	uart[0] = 1;
	write(fd, uart, 1);
	read(fd, uart, 1); 
	resp = uart[0] & 0xFF;

	status = 1;
	while (status) 
		status = FAZIA_status(fd);

	return resp;
}

int FAZIA_unprotect(int fd)
{
	int resp;
	unsigned char uart[2];
	int status;

	uart[0] = 2;
	//printf("write %d\n", uart[0]);
	write(fd, uart, 1);
	//printf("read %d\n", uart[0]);
	read(fd, uart, 1); 
	//printf("resp %d\n", uart[0]);
	resp = uart[0] & 0xFF;
	//printf("resp %d\n", resp);

	status = 1;
	while (status) 
		status = FAZIA_status(fd);

	return resp;
}

int FAZIA_status(int fd)
{
	int status;
	unsigned char uart[2];

	uart[0] = 6;
	write(fd, uart, 1);
	read(fd, uart, 1); 
	status = uart[0] & 0xFF;

	return status;
}

int FAZIA_erase(int fd, int sector)
{
	int resp;
	unsigned char uart[2];
	int status;

	uart[0] = 3;
	uart[1] = sector & 0xFF;
	write(fd, uart, 2);
	read(fd, uart, 1); 
	resp = uart[0] & 0xFF;

	status = 1;
	while (status) 
		status = FAZIA_status(fd);

	return resp;
}

int FAZIA_write(int fd, int sector, int page, unsigned char *data)
{
	int resp;
	unsigned char uart[259];
	int status;
	int i;

	uart[0] = 4;
	uart[1] = sector & 0xFF;
	uart[2] = page & 0xFF;
	for (i = 0; i < 256; i++)
		uart[i + 3] = data[i];
	write(fd, uart, 259);
	read(fd, uart, 1); 
	resp = uart[0] & 0xFF;

	status = 1;
	while (status) 
		status = FAZIA_status(fd);

	return resp;
}

void FAZIA_read(int fd, int sector, int page, unsigned char *data)
{
	unsigned char uart[3];
	int i;

	uart[0] = 5;
	uart[1] = sector & 0xFF;
	uart[2] = page & 0xFF;
	write(fd, uart, 3);
	for (i = 0; i < 256; i++) {
		read(fd, uart, 1); 
		data[i] = uart[0];
	}
}

int FAZIA_merge(char *filename_a, char *filename_b, unsigned char *data)
{
	int file_size_a;
	int file_size_b;
	int file_size;
	FILE *fp;
	unsigned char *rdat_a;
	unsigned char *rdat_b;
	int i;

	if ((access(filename_a, 0)) != 0) {
		printf("%s is not found!\n", filename_a);
		return 0;
	}

	if ((access(filename_b, 0)) != 0) {
		printf("%s is not found!\n", filename_b);
		return 0;
	}

	fp = fopen(filename_a, "rb");
	fseek(fp, 0L, SEEK_END);
	file_size_a = ftell(fp);
	fclose(fp);

	fp = fopen(filename_b, "rb");
	fseek(fp, 0L, SEEK_END);
	file_size_b = ftell(fp);
	fclose(fp);

	rdat_a = (unsigned char *)malloc(file_size_a); 
	rdat_b = (unsigned char *)malloc(file_size_b); 

	fp = fopen(filename_a, "rb");
	fread(rdat_a, 1, file_size_a, fp);
	fclose(fp);

	fp = fopen(filename_b, "rb");
	fread(rdat_b, 1, file_size_b, fp);
	fclose(fp);

	if (file_size_b > file_size_a)
		file_size = file_size_b;
	else
		file_size = file_size_a;

	for (i = 0; i < file_size; i++) {
		data[2 * i] = rdat_a[i] & 0x80;
		data[2 * i] = data[2 * i] + ((rdat_b[i] & 0x80) >> 1);
		data[2 * i] = data[2 * i] + ((rdat_a[i] & 0x40) >> 1);
		data[2 * i] = data[2 * i] + ((rdat_b[i] & 0x40) >> 2);
		data[2 * i] = data[2 * i] + ((rdat_a[i] & 0x20) >> 2);
		data[2 * i] = data[2 * i] + ((rdat_b[i] & 0x20) >> 3);
		data[2 * i] = data[2 * i] + ((rdat_a[i] & 0x10) >> 3);
		data[2 * i] = data[2 * i] + ((rdat_b[i] & 0x10) >> 4);

		data[2 * i + 1] = (rdat_a[i] & 0x08) << 4;
		data[2 * i + 1] = data[2 * i + 1] + ((rdat_b[i] & 0x08) << 3);
		data[2 * i + 1] = data[2 * i + 1] + ((rdat_a[i] & 0x04) << 3);
		data[2 * i + 1] = data[2 * i + 1] + ((rdat_b[i] & 0x04) << 2);
		data[2 * i + 1] = data[2 * i + 1] + ((rdat_a[i] & 0x02) << 2);
		data[2 * i + 1] = data[2 * i + 1] + ((rdat_b[i] & 0x02) << 1);
		data[2 * i + 1] = data[2 * i + 1] + ((rdat_a[i] & 0x01) << 1);
		data[2 * i + 1] = data[2 * i + 1] + (rdat_b[i] & 0x01);
	}

	for (i = file_size; i < 6693120; i++) {
		data[2 * i] = 0x00;
		data[2 * i + 1] = 0x00;
	}

	return 1;
}

int main(int argc, char *argv[])
{
	char filename_a[256];
	char filename_b[256];
	unsigned char *data;
	int file_exist;
	FILE *fp;
	int serial_port;
	int nsector;
	int sector;
	int npage;
	int page;
	int page_size;
	unsigned char rdat[256];
	int error_count;
	int addr;

	if (argc < 3) {
		printf("enter filename A : ");
		scanf("%s", filename_a);
		printf("enter filename B : ");
		scanf("%s", filename_b);
	}
	else {
		sprintf(filename_a, "%s", argv[1]);
		sprintf(filename_b, "%s", argv[2]);
	}

	data = (unsigned char *)malloc(13386240); 

	file_exist = FAZIA_merge(filename_a, filename_b, data);

	if (file_exist) {
		fp = fopen("merge.bit", "wt");
		fwrite(data, 1, 13386240, fp);
		fclose(fp);

		nsector = 204;
		    //nsector = 1;
		npage = 66;
		page_size = nsector * 256 + npage;

		// open serial port
		printf("serial_port open \n");
		serial_port = FAZIA_open("/dev/ttyUSB0");





	//while (1) FAZIA_status(serial_port);





		// write firmware
		// unprotect flasg memory
		printf("FAZIA_unprotect \n");
		FAZIA_unprotect(serial_port);

		printf("for loop \n");
		for (sector = 0; sector < nsector; sector++) {
			// erase sector
			FAZIA_erase(serial_port, sector);

			// write firmware
			for (page = 0; page < 256; page++) {
				FAZIA_write(serial_port, sector, page, data + sector * 65536 + page * 256);
				printf("%d / %d programmed\n", sector * 256 + page + 1, page_size);
			}
		}

		// erase sector
		printf("one more erase \n");
		FAZIA_erase(serial_port, nsector);

		// write firmware
		printf("write firmware \n");
		for (page = 0; page < npage; page++) {
			FAZIA_write(serial_port, nsector, page, data + nsector * 65536 + page * 256);
			//printf("%d / %d programmed\n", nsector * 256 + page + 1, page_size);
		}

		// protect flash memory
		//printf("protect \n");
		FAZIA_protect(serial_port);

		// verify firmware
		error_count = 0;

    /*
		for (sector = 0; sector < nsector; sector++) {
			for (page = 0; page < 256; page++) {
				// read firmware
				FAZIA_read(serial_port, sector, page, rdat);

				// verify firmware
				for (addr = 0; addr < 256; addr++) {
					if (rdat[addr] != data[sector * 65536 + page * 256 + addr]) {
						printf("error = %d, %X : %X : %X, returned = %X, expected = %X\n", error_count
								, sector, page, addr, rdat[addr] & 0xFF, data[sector * 65536 + page * 256 + addr] & 0xFF);
						error_count = error_count + 1;
						if (error_count > 99) {
							sector = nsector;
							page = 256;
							addr = 256;
							printf("Too many errors!\n");
						}
					}
				}

				//printf("%d / %d verified\n", sector * 256 + page + 1, page_size);
			}      
		}

		if (error_count < 100) {
			for (page = 0; page < npage; page++) {
				// read firmware
				FAZIA_read(serial_port, nsector, page, rdat);

				// verify firmware
				for (addr = 0; addr < 256; addr++) {
					if (rdat[addr] != data[nsector * 65536 + page * 256 + addr]) {
						printf("error = %d, %X : %X : %X, returned = %X, expected = %X\n", error_count
								, sector, page, addr, rdat[addr] & 0xFF, data[nsector * 65536 + page * 256 + addr] & 0xFF);
						error_count = error_count + 1;
						if (error_count > 99) {
							page = npage;
							addr = 256;
							printf("Too many errors!\n");
						}
					}
				}

				printf("%d / %d verified\n", nsector * 256 + page + 1, page_size);
			}      
		}
    */

		FAZIA_close(serial_port);
	}

	free(data);

	return 0;
}

