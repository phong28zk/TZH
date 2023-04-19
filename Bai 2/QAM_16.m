clear all;
close all;

M = 16; % Modulation order
k = log2(M); % Number of bits per symbol
EbNoVec = -10:2:20; % SNR range in dB
EbNo = 10.^(EbNoVec/10); % SNR range in linear scale
d = sqrt(3/(2*(M-1))); % Distance between adjacent constellation points
Es = (M-1)*d^2; % Energy per symbol
Eb = Es/k; % Energy per bit
N0 = Eb./EbNo; % Noise power spectral density
berTheory = 
% Plot theoretical BER
semilogy(EbNoVec,berTheory)
xlabel('Eb/No (dB)')
ylabel('Bit Error Rate')
title('16-QAM Theoretical Bit Error Rate')
grid on
datacursormode on
