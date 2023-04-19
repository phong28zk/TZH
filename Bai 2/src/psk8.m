clear all;
close all;

SNR_db = -10:2:10;
SNR = 10.^(SNR_db/10);

M = 8;
k = log2(M);

PSK8 = 2*qfunc(sqrt(4*k*SNR)*sin(pi/(2*M)));
PSK8_sim = [0.7256 0.6789 0.62 0.5444 0.4526 0.3469 0.2382 0.1369 0.0622 0.0192 0.00285];     

theoritical = semilogy(SNR_db, PSK8, 'r');
hold on;
practical = semilogy(SNR_db, PSK8_sim, 'b');
hold on;

xlabel('SNR (dB)');
ylabel('BER');

legend([theoritical practical], 'Theoritical', 'Practical');
hold on;
datacursormode on;