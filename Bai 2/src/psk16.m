clear all;
close all;

SNR_db = -10:2:10;
SNR = 10.^(SNR_db/10);

M = 16; 
k = log2(M);

PSK16 = 2*qfunc(sqrt(4*k*SNR)*sin(pi/(2*M)));
PSK16_sim = [0.896 0.8843 0.8671 0.8456 0.8166 0.776 0.7241 0.66 0.582 0.489 0.3842];   
theoritical = semilogy(SNR_db, PSK16, 'r--+');
hold on;
practical = semilogy(SNR_db, PSK16_sim, 'b--+');
hold on;

legend([theoritical practical], 'Theoritical', 'Practical');
xlabel('SNR(db)');
ylabel('BER');
hold on;
grid on;
datacursormode on;