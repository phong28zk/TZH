function [b,d]=stair_func(n)
    %Chuyen doi dang luong cuc
    b=[];
    b=randi([0 1],1,n);
    d=[];
    % b=0 => d=1, b=1 => d=-1 ==> d=1-2*b
    for i=1:n
        % d=-1*b
        d(i)=1-2*b(i);
    end
    
    subplot(2,1,1);
    stairs(b,'r','linewidth',2);
    axis([0 n+1 -2 2]);

    subplot(2,1,2);
    stairs(d,'b','linewidth',2);
    axis([0 n+1 -2 2]);
end