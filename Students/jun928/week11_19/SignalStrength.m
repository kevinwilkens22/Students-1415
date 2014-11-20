
p = 0.2; %Set p for translation to the four direction 
q = 0.4; %rotation
xm =0;
ym=0;
xg = 10;
yg = 10;
%Number of steps
N = 100;
M =45; %Number of signals
energy = 0;
theta = 0;%Toward the north
Pt = 10^5;
A = 1.62e-2;%uniform energy for each signal 
B = 11.2; %distance coefficient 
Av = 100;
%How much energy/ power is being used
check=0;
for h = 1:Av%for averaging
    for j = 1:M
        xm = 0;
        ym= 0;%Reset the coordinate for signal
        %Random Number Vector for probability each turn
        a =0;
        b=1;
        r_1 = (b-a).*rand(N,1) + a;
        r_2 = (b-a).*rand(N,1) + a;
        for i = j:N
            if(r_2(i)<q)&(r_2(i)>=0)
                theta= theta+pi/4;
            elseif(r_2(i)<2*q)&(r_2(i)>=q)
                theta=theta-pi/4;
            end
            while(theta>2*pi)||(theta<-2*pi)
                
                if (theta >2*pi)
                    theta= theta-2*pi;
                elseif(theta<-2*pi)
                    theta = theta+2*pi;
                end
            end
            
            if (r_1(i)<p)&(r_1(i)>=0)
                ym = ym+1;
            elseif (r_1(i)<2*p)&(r_1(i)>=p)
                xm = xm+1;
            elseif (r_1(i)<3*p)&(r_1(i)>=2*p)
                ym = ym-1;
            elseif (r_1(i)<4*p)&(r_1(i)>=3*p)
                xm = xm-1;
            end
            if (xm ~= xg)&(ym ~=yg)
                d = sqrt((xg-xm)^2+(yg-ym)^2);
            else
                d = 1;
            end
            angle = atan((yg-ym)/(xg-xm));
            theDif= abs((angle-theta)*180/2/pi);
            if (theDif ==0)
                theDif = 1;
            end
            energy = energy +A*d^(-B);%ty%/theDif;
            check = check+A;
        end
    end
end
check
energy = energy/Av;
energy
   
