clc;
close all;
EbNo_db = -5:1:25;
EbNo_lin = 10.^((EbNo_db)/10);
color = ['r','g','b','k','m','c','y'];
index = 1;

BPSK = 0.5*erfc(sqrt(EbNo_lin));
plotHandle = plot(EbNo_db, log10(BPSK), char(color(index)));
set(plotHandle, 'LineWidth', 2);
hold on;
index = index + 1;

n = 2:1:5;
M = 2.^n;
for i = M,
    k = log2(i);
    BER = 1/k*erfc(sqrt(EbNo_lin*k*sin(pi/i)));
    plotHandle = plot(EbNo_db, log10(BER), char(color(index)));
    set(plotHandle, 'LineWidth', 2);
    index = index + 1;
end

