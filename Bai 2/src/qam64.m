clear all;
close all;

SNR_db = -10:2:10;
SNR = 10.^(SNR_db/10);
M = 64;
k = log2(M);

QAM16 = 4*(1-1/sqrt(M))*qfunc(sqrt(3*k*SNR/(M-1)));
QAM16_sim = [0.7388 0.6737 0.5873 0.4785 0.352 0.2214 0.1098 0.0365 0.00676 0.00058 9e-6];

theoritical = semilogy(SNR_db,QAM16,'r+--');
hold on;
practical = semilogy(SNR_db,QAM16_sim,'b+--');
hold on;

legend([theoritical practical],'Theoritical','Practical');
xlabel('SNR (dB)');
ylabel('BER');

hold on;
datacursormode on;