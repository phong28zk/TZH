clear all;
close all;
clc;

SNR_db = -10:1:10;
SNR_ln = 10.^((SNR_db)/10);
num_bits = 1e5;
bits = randi([0 1],1,num_bits);

symbols = 1 - 2*bits;
BER = zeros(size(SNR_ln));
for i = 1:length(SNR_ln)
    rx_symbols = symbols + sqrt(snr(i)/2)*randn(size(symbols));
    rx_bits = rx_symbols > 0;
    rx_bits = rx_bits(:);
    n_err = sum(rx_bits ~= bits);
    BER(i) = n_err/num_bits;
end

theory_ber = 0.5*erfc(sqrt(SNR_ln));

semilogy(snr_db, ber, 'o-', 'LineWidth', 2);
hold on;
semilogy(snr_db, theory_ber, 'r-', 'LineWidth', 2);
xlabel('SNR (dB)');
ylabel('Bit Error Rate');
title('BPSK Modulation and Demodulation');
legend('Simulated BER', 'Theoretical BER');

