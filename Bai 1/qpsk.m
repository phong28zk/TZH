function qpsk(b1,b2)
x = 0: 0.1 : 2*pi;
z = cos(x);
y = -sin(x);
s = b1*y + b2*z;
t = cos(x + pi/4);
subplot(3,1,1);
plot(x,y);
subplot(3,1,2);
plot(x,z);
subplot(3,1,3);
plot(x,s);
end