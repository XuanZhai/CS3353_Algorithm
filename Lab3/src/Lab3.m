x = [4,5,6,7,8,9,10,11,12,13];
y1 = [0,0,0,1.2101,4.0163,29.0366,283.257,3099.94,35736.4,505201];
y2 = [0, 0.9904, 2.0018, 3.0014, 10.0217, 37.5871, 141.127, 591.536, 2510.34, 13033.4];

y01 = [24,120,720,5040,40320,362880,3628800,39916800,479001600,7227020800];
y02 = [256,800,2304,6272,16384,41472,102400,247808,589824,1384448];
y31 = zeros(1,10);
y32 = zeros(1,10);

for i= 1:1:10
    y31(i) = y1(i)/ y01(i);
    y32(i) = y2(i)/y02(i);
end

figure(1);
plot(x,y1,'ro-', x,y2, 'bo-');
xlabel('n');
ylabel('ms');
title('Time to find shortest path');
grid on;
legend('Navie', 'Dynamic');

y11 = [0,0,0,1.0048,8.0384,72.3456, 723.456, 7958.016, 95496.192, 1241450.496];
y22 = [0,0.9904, 2.852352, 7.764736, 20.283392, 51.342336, 126.7712, 306.786304, 730.202112, 1713.946624];

figure(2);
plot(x,y1,'ro-', x,y11, 'bo-');
xlabel('n');
ylabel('ms');
title('Comparison for The Naive Method');
grid on;
legend('Asymptotic', 'Simulatied');



figure(3);
plot(x,y2,'ro-', x,y22, 'bo-');
xlabel('n');
ylabel('ms');
title('Comparison for The Dynamic Programming Method');
grid on;
legend('Asymptotic', 'Simulatied');

figure(4);
plot(x,y31,'ro-');
xlabel('n');
ylabel('ms');
title('Naive Method operation time');
grid on;
legend('Single Operation time');

figure(5);
plot(x,y32,'ro-');
xlabel('n');
ylabel('ms');
title('Dynamic Programming Method operation time');
grid on;
legend('Single Operation time');