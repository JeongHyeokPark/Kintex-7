{
  FILE *fp;
  int i;
  int j;
  int k;
  int lut[128][8];
  int lsb[32];
  int msb[32];
  int value[128];
  int rom[8][32];

  value[0] = 0b00101101; value[1] = 0b00101101; value[2] = 0b00101101; value[3] = 0b00101101; value[4] = 0b00101101; value[5] = 0b00101101; value[6] = 0b00101101; value[7] = 0b00101101; value[8] = 0b00000000; value[9] = 0b00000000;
  value[10] = 0b00000000; value[11] = 0b00000000; value[12] = 0b00000000; value[13] = 0b00000000; value[14] = 0b00000000; value[15] = 0b00000000; value[16] = 0b00100110; value[17] = 0b00100110; value[18] = 0b00100110; value[19] = 0b00100110;
  value[20] = 0b00100110; value[21] = 0b00100110; value[22] = 0b00100110; value[23] = 0b00100110; value[24] = 0b00001010; value[25] = 0b00000000; value[26] = 0b00000000; value[27] = 0b00000000; value[28] = 0b00000000; value[29] = 0b00000000;
  value[30] = 0b00000000; value[31] = 0b00000000; value[32] = 0b00100110; value[33] = 0b00100110; value[34] = 0b00100110; value[35] = 0b00100110; value[36] = 0b00100110; value[37] = 0b00100110; value[38] = 0b00100110; value[39] = 0b00100110;
  value[40] = 0b00001010; value[41] = 0b00000000; value[42] = 0b00000000; value[43] = 0b00000000; value[44] = 0b00000000; value[45] = 0b00000000; value[46] = 0b00000000; value[47] = 0b00000000; value[48] = 0b00101101; value[49] = 0b00101101;
  value[50] = 0b00101101; value[51] = 0b00101101; value[52] = 0b00101101; value[53] = 0b00101101; value[54] = 0b00101101; value[55] = 0b00101101; value[56] = 0b00000000; value[57] = 0b00000000; value[58] = 0b00000000; value[59] = 0b00000000;
  value[60] = 0b00000000; value[61] = 0b00000000; value[62] = 0b00000000; value[63] = 0b00000000; value[64] = 0b00100110; value[65] = 0b00100110; value[66] = 0b00100110; value[67] = 0b00100110; value[68] = 0b00100110; value[69] = 0b00100110;
  value[70] = 0b00100110; value[71] = 0b00100110; value[72] = 0b00001010; value[73] = 0b00000000; value[74] = 0b00000000; value[75] = 0b00000000; value[76] = 0b00000000; value[77] = 0b00000000; value[78] = 0b00000000; value[79] = 0b00000000;
  value[80] = 0b00101101; value[81] = 0b00101101; value[82] = 0b00101101; value[83] = 0b00101101; value[84] = 0b00101101; value[85] = 0b00101101; value[86] = 0b00101101; value[87] = 0b00101101; value[88] = 0b00000000; value[89] = 0b00000000;
  value[90] = 0b00000000; value[91] = 0b00000000; value[92] = 0b00000000; value[93] = 0b00000000; value[94] = 0b00000000; value[95] = 0b00000000; value[96] = 0b00000000; value[97] = 0b00000000; value[98] = 0b00000000; value[99] = 0b00000000;
  value[100] = 0b00000000; value[101] = 0b00000000; value[102] = 0b00000000; value[103] = 0b00000000; value[104] = 0b00000000; value[105] = 0b00000000; value[106] = 0b00000000; value[107] = 0b00000000; value[108] = 0b00000000; value[109] = 0b00000000;
  value[110] = 0b00000000; value[111] = 0b00000000; value[112] = 0b00000000; value[113] = 0b00000000; value[114] = 0b00000000; value[115] = 0b00000000; value[116] = 0b00000000; value[117] = 0b00000000; value[118] = 0b00000000; value[119] = 0b00000000;
  value[120] = 0b00000000; value[121] = 0b00000000; value[122] = 0b00000000; value[123] = 0b00000000; value[124] = 0b00000000; value[125] = 0b00000000; value[126] = 0b00000000; value[127] = 0b00000000; 
  /*
     for (i = 0; i < 32; i++) 
     value[i] = lsb[i] + 65536 * msb[i];

   */
     for (i = 0; i < 128; i++) {
      for (j = 0; j < 8; j++) {
        lut[i][j] = (value[i] >> j) & 0x1;
        }
      }


  for (j = 0; j < 8; j++) {
    printf("lut[2][%d] = %d, value = %X\n", j, lut[2][j], (value[2] >> j) & 0x1);
  }


  for (i = 0; i < 8; i++) {
    for (j = 0; j < 32; j++) {
      rom[i][j] = 0;
      for (k = 0; k < 4; k++) {
        rom[i][j] = rom[i][j] + (lut[j * 4 + k][i] << k);
      }
    }
  }

  fp = fopen("aligner_lut.txt", "wt");

  for (i = 0; i < 8; i++) {
    fprintf(fp, "   rom128x1_aligner_rom_%d : ROM128X1\n", i);
    fprintf(fp, "   generic map (INIT => X\"");
    fprintf(fp, "%X", rom[i][31]);
    fprintf(fp, "%X", rom[i][30]);
    fprintf(fp, "%X", rom[i][29]);
    fprintf(fp, "%X", rom[i][28]);
    fprintf(fp, "%X", rom[i][27]);
    fprintf(fp, "%X", rom[i][26]);
    fprintf(fp, "%X", rom[i][25]);
    fprintf(fp, "%X", rom[i][24]);
    fprintf(fp, "%X", rom[i][23]);
    fprintf(fp, "%X", rom[i][22]);
    fprintf(fp, "%X", rom[i][21]);
    fprintf(fp, "%X", rom[i][20]);
    fprintf(fp, "%X", rom[i][19]);
    fprintf(fp, "%X", rom[i][18]);
    fprintf(fp, "%X", rom[i][17]);
    fprintf(fp, "%X", rom[i][16]);
    fprintf(fp, "%X", rom[i][15]);
    fprintf(fp, "%X", rom[i][14]);
    fprintf(fp, "%X", rom[i][13]);
    fprintf(fp, "%X", rom[i][12]);
    fprintf(fp, "%X", rom[i][11]);
    fprintf(fp, "%X", rom[i][10]);
    fprintf(fp, "%X", rom[i][9]);
    fprintf(fp, "%X", rom[i][8]);
    fprintf(fp, "%X", rom[i][7]);
    fprintf(fp, "%X", rom[i][6]);
    fprintf(fp, "%X", rom[i][5]);
    fprintf(fp, "%X", rom[i][4]);
    fprintf(fp, "%X", rom[i][3]);
    fprintf(fp, "%X", rom[i][2]);
    fprintf(fp, "%X", rom[i][1]);
    fprintf(fp, "%X", rom[i][0]);
    fprintf(fp, "\")\n");
    fprintf(fp, "   port map (\n");
    fprintf(fp, "      A0 => a(0),\n");
    fprintf(fp, "      A1 => a(1),\n");
    fprintf(fp, "      A2 => a(2),\n");
    fprintf(fp, "      A3 => a(3),\n");
    fprintf(fp, "      A4 => a(4),\n");
    fprintf(fp, "      A5 => a(5),\n");
    fprintf(fp, "      A6 => a(6),\n");
    fprintf(fp, "      O => spo(%d)\n", i);
    fprintf(fp, "   )\;\n");
    fprintf(fp, "\n");
  }

  fclose(fp);
}
