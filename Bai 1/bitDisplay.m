function [] = bitDisplay(b)
%Ve chuoi bit dang xung vuong

stairs(b,'r','LineWidth',2)
axis([0 length(b)+1 -2 2])

end

