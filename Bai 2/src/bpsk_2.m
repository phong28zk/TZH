clear all;
close all;

SNR_dB = -10:2:10;          % SNR values in dB
SNR_ln = 10.^(SNR_dB/10);   % SNR values in linear scale
BER = [0.3288 0.2866 0.2392 0.1867 0.131 0.08 0.0385 0.0131 0.00255 0.00018 2e-6]
figure;
prac = semilogy(SNR_dB, BER, 'b*-');
hold on;
theoritical = semilogy(SNR_dB, 0.5*erfc(sqrt(SNR_ln)), 'r*-');


xlabel('SNR in db');
ylabel('BER');
legend([prac theoritical],'Practical','Theoritical');
grid on;
datacursormode on;
