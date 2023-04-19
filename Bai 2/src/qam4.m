clear all;
close all;

SNR_db = -10:2:10;
SNR = 10.^(SNR_db/10);

M = 4;
k = log2(M);

QAM4 = 4*(1-1/sqrt(M))*Q(sqrt(3*))