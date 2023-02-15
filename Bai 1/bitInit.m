function [b,d] = bitInit(n)
%Khoi tao chuoi bit co do dai n
b = [];
b = randi([0 1],1,n);

d = [];
for i = 1:n
    %d(i) = 1 - 2*b(i);
    if b(i)==0
        d(i) = 1;
    else
        d(i) = -1;
    end
end

subplot(2,1,1);
stairs(b,'r','linewidth',2);
axis([0 n+1 -2 2]);

subplot(2,1,2);
stairs(d,'r','linewidth',2);
axis([0 n+1 -2 2]);
end

