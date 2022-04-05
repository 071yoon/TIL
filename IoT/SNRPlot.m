dB = 0:30;
logdB = 10.^(dB/10);
AWGN = erfc(sqrt(logdB)); % AWGN
Rayleigh = 0.5.*(1-sqrt(logdB./(logdB+1))); %Rayleigh

figure(1)
semilogy(dB(1:2:end),AWGN(1:2:end),'o'); %plot every 2nd
hold on
semilogy(dB(1:2:end),Rayleigh(1:2:end),'*'); %plot every 2nd
axis([0 30 10^-6 0.5]) %important : -1 to -3
grid on
legend('AWGN','Rayleigh');
xlabel('SNR(dB)');
ylabel('P(e)');
title('AWGN and Rayleigh Figure');