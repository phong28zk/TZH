clear all;
close all;

SNR_db = -10:2:10;
SNR = 10.^(SNR_db/10);

M = 4;
k = log2(M);

% 4-QAM theoritical
QAM4 = 4*(1-1/sqrt(M))*qfunc(sqrt(3*k*SNR/(M-1)));
QAM4_sim = [0.5502 0.4982 0.4258 0.3366 0.2433 0.1481 0.0769 0.0276 0.00569 0.0005 8e-6];

theoritical = semilogy(SNR_db, QAM4, 'r--+');
hold on;
practical = semilogy(SNR_db, QAM4_sim, 'b--+');
hold on;

legend([theoritical practical], 'Theoritical', 'Practical');
xlabel('SNR(db)');
ylabel('BER');
hold on;
grid on;
datacursormode on;