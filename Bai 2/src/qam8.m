clear all;
close all;

SNR_db = -10:2:10;
SNR = 10.^(SNR_db/10);

M = 8;
k = log2(M);

% 4-QAM theoritical
QAM8 = 4*(1-1/sqrt(M))*qfunc(sqrt(3*k*SNR/(M-1)));
QAM8_sim = [0.6577 0.6009 0.5171 0.4126 0.3018 0.1893 0.09579 0.0344 0.0067 0.0005 9e-6];

theoritical = semilogy(SNR_db, QAM8, 'r--+');
hold on;
practical = semilogy(SNR_db, QAM8_sim, 'b--+');
hold on;

legend([theoritical practical], 'Theoritical', 'Practical');
xlabel('SNR(db)');
ylabel('BER');
hold on;
grid on;
datacursormode on;