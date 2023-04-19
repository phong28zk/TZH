clear all;
close all;
clc;

SNR_db = -8:1:15;
SNR_ln = 10.^(SNR_db/10);
No_bits = 1e5;
bits = randi([0 1],1,No_bits);
x_bpsk = 1 - 2*bits;
n = randn(1,No_bits);

for k=1:length(SNR_ln)
    y = sqrt(SNR_ln(k))*x_bpsk + n;
    noisy_bits = y.*x_bpsk;
    cr = find(noisy_bits<0);
    NumOfCr(k) = length(find(cr));
end

BER = NumOfCr/No_bits;
figure;
prac = semilogy(SNR_db,BER,'r');
hold on;
theoritical = semilogy(SNR_db,0.5*qfunc(sqrt(SNR_ln)),'b');

xlabel('SNR in db');
ylabel('BER');
legend([prac theoritical],'Practical','Theoritical');
grid on;
datacursormode on;


