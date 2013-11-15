clear all;
hold on

fid = fopen('1_input_field.txt');
num = fscanf(fid,'%d',3);
for i = 1 : num(1)
for j = 1 : num(2)
   c(i,j) = fscanf(fid, '%f',1);
end
end
c(end+1,:)=0;
c(:,end+1)=0;
fclose(fid);

[X,Y]= meshgrid(0.5:1:num(2)+1,0.5:1:num(1)+1);
pcolor(X,Y,c) 
colormap([1 1 1;0.4392 0.7466656 1]);
%colormap([0.7 0.7 0.7;1 1 1;0.4392 0.7466656 1]);
%colormap([1 1 1;0.2 0.35 0]);
%axis ij 
axis square
axis tight


th = [0:0.1:2*pi,0];
fid = fopen('1_2_map_deployment.txt');
r= fscanf(fid,'RS=%lf RT=%lf');
rs = r(1); rt = r(2);


fgetl(fid);fgetl(fid);
string=fgetl(fid);

index=1;
for i = 1 : num(1)
for j = 1 : num(2)
   temp = fscanf(fid, '%d',1);
   if temp == 2
        x(index)=i;
        y(index)=j;
        index=index+1;     
   end
end
end


title(string);
axis ij
axis tight


plot(y,x,'b.');                       

for i = 1 : index-1
    plot(y(i)+rs*cos(th),x(i)+rs*sin(th),'r--'); 
  %  plot(y(i)+rt*cos(th),x(i)+rt*sin(th),'g-');
end

    fgetl(fid);
    fgetl(fid);
    fgetl(fid);
    index=1;
    for i = 1 : num(1)
    for j = 1 : num(2)
       temp = fscanf(fid, '%d',1);
       if temp == 2
            x(index)=i;
            y(index)=j;
            index=index+1;     
       end
    end
    end
    fclose(fid);
    plot(y,x,'b.');


hold off







