Fs = 1000;                    % Sampling frequency
Ts = 1/Fs;                    % Sample time
L = 1000;                     % Length of signal: 1000 sample points
t = (0:L-1)*Ts;               % Time vector, totally 1 second

% Sum of a 50 Hz sinusoid and a 120 Hz sinusoid
x = 0.7*sin(2*pi*50*t) + sin(2*pi*120*t); 
y = x + 2*randn(size(t));     % Sinusoids plus random noise
plot(t,y)
title('Signal Corrupted with Zero-Mean Random Noise')
xlabel('time (seconds)')

% FFT calculation
NFFT = 2^nextpow2(L); % Next power of 2 from length of y : 1024
Y = fft(y,NFFT)/L;
%f = (Fs/2)*linspace(0,1,NFFT/2+1); % Single-sided frequency
f = (Fs)*linspace(0,1,NFFT); % Single-sided frequency

figure
% Plot amplitude spectrum.
plot(f, abs(Y)) 
title('Single-Sided Amplitude Spectrum of y(t)')
xlabel('Frequency (Hz)')
ylabel('|Y(f)|')