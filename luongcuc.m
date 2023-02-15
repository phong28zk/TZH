function [b,d]=luongcuc(n)
    %Chuyen doi dang luong cuc
    b=[];
    b=randi([0 1],1,n);
    d=[];
    % b=0 => d=1, b=1 => d=-1 ==> d=1-2*b
    for i=1:n
        % d=-1*b
        d(i)=1-2*b(i);
    end
end