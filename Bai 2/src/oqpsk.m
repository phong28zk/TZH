clear all;
close all;

SNR_db = -10:2:10;
SNR = 10.^(SNR_db/10);

OQPSK = 2*qfunc(sqrt(2*SNR));
OQPSK_sim = [0.55 0.4932 0.4233 0.3386 0.246 0.1521 0.07403 0.02496 0.00486 0.00043 1e-5];

figure;
practical = semilogy(SNR_db, OQPSK_sim, 'r', 'LineWidth', 2);
hold on;
theoritical = semilogy(SNR_db, OQPSK, 'b', 'LineWidth', 2);
hold on;
xlabel('SNR (dB)');
ylabel('BER');
legend([practical theoritical], 'Practical', 'Theoritical');
hold on;
datacursormode on;