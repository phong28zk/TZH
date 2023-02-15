function y = vidu(A,T,N)
 
s = [];
t = 0:0.1:T;
s = A.*sin(t);
%for i = 1:length(t)
%    s(i) = A;
%end

n =[];
for i = 1:length(t)
n(i) = N*random('Normal',0,1);
end

y = s + n;

%subplot(3,1,1);
plot(t,s,'g','linewidth',2);
axis([0 T+1 -(A+max(n)+1) (A+max(n)+1)]);
hold on;
%subplot(3,1,2);
plot(t,n,'r--');
axis([0 T+1 -(A+max(n)+1) (A+max(n)+1)]);

%subplot(3,1,3);
plot(t,y,'k-.', 'linewidth',2);
axis([0 T+1 -(A+max(n)+1) (A+max(n)+1)]);
hold off;
grid on;
end   