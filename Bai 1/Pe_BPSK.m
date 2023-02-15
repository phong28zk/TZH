function Pe_BPSK()

EbNo_dB = -5:10;
EbNo = 10.^(EbNo_dB/10);
Pe_BPSK = qfunc(sqrt(2*EbNo));

EbNo_simul = [-5 0 5 10];
Pe_BPSK_simul = [0.2135 0.07892 0.005987 0];

semilogy(EbNo_dB,Pe_BPSK, EbNo_simul, Pe_BPSK_simul,'r--+', 'linewidth',2)


end

