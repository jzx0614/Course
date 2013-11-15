clear all;
colordef white

map_id =2;
%rt_id = 4;
RS_Group = 6;

rt_group=[3,5,6,6,6,6];

% 依比例畫圖 start
rt_shift=[-3,-1,0,0,0,0];

for rt_id = 1 :4
index =1;
for i = 2 : RS_Group
%    filename = [num2str(i) '_RS\' num2str(map_id) '_' num2str(rt_id+rt_shift(i)) '_map_deployment.txt'];
    filename = [num2str(i) '_RS\' num2str(map_id) '_' num2str(rt_id) '_map_deployment.txt'];
    fid = fopen(filename);
    if fid ~= -1  
        
        fgetl(fid);fgetl(fid);
        node_weight(index)=fscanf(fid,'sensor num= %d');
        fclose(fid);
        
%        filename_2 = [num2str(i) '_RS\' num2str(map_id) '_' num2str(rt_id+rt_shift(i)+rt_group(i)) '_map_deployment.txt'];
        filename_2 = [num2str(i) '_RS\' num2str(map_id) '_' num2str(rt_id+4) '_map_deployment.txt'];
        fid_2 = fopen(filename_2);
        fgetl(fid_2);fgetl(fid_2);
        spann(index)=fscanf(fid_2,'sensor num= %d');
        fclose(fid_2); 
        
%        filename_3 = [num2str(i) '_RS\' num2str(map_id) '_' num2str(rt_id+rt_shift(i)+rt_group(i)*2) '_map_deployment.txt'];
        filename_3 = [num2str(i) '_RS\' num2str(map_id) '_' num2str(rt_id+4*2) '_map_deployment.txt'];
        fid_3 = fopen(filename_3);
        fgetl(fid_3);fgetl(fid_3);
        water(index)=fscanf(fid_3,'sensor num= %d');
        fclose(fid_3);         
        
        index = index + 1;
    end
end
subplot(2,2,rt_id);

out_filename = [num2str(map_id) '_' num2str(rt_id) '_number.csv'];
fout = fopen(out_filename,'w');
fprintf(fout,'node_weight\r\n');
fprintf(fout,'%d,',node_weight);
fprintf(fout,'\r\nspanning\r\n');
fprintf(fout,'%d,',spann);
fprintf(fout,'\r\nwater\r\n');
fprintf(fout,'%d,',water);
fclose(fout);
% 依比例畫圖 end

% 固定RS畫圖 start
% for i = 1 : RS_Group
% index = 1;    
% for j = 1 : rt_group(i)
%     filename = [num2str(i) '_RS\' num2str(map_id) '_' num2str(j) '_map_deployment.txt'];
%     fid = fopen(filename);
%     fgetl(fid);fgetl(fid);
%     node_weight(index)=fscanf(fid,'sensor num= %d');
%     fclose(fid);
% 
%     filename_2 = [num2str(i) '_RS\' num2str(map_id) '_' num2str(j+rt_group(i)) '_map_deployment.txt'];
%     fid_2 = fopen(filename_2);
%     fgetl(fid_2);fgetl(fid_2);
%     spann(index)=fscanf(fid_2,'sensor num= %d');
%     fclose(fid_2); 
% 
%     filename_3 = [num2str(i) '_RS\' num2str(map_id) '_' num2str(j+rt_group(i)*2) '_map_deployment.txt'];
%     fid_3 = fopen(filename_3);
%     fgetl(fid_3);fgetl(fid_3);
%     water(index)=fscanf(fid_3,'sensor num= %d');
%     fclose(fid_3);         
% 
%     index = index + 1;
% 
% end
% subplot(2,3,i);
% 固定RS畫圖 end

plot(node_weight,'r*:');  hold on
plot(spann,'k.-');        hold on
plot(water,'bx-.');        hold on

for i = 1 : length(node_weight)
   text(i+0.1,node_weight(i)+1,[num2str(100*(spann(i)-node_weight(i))/node_weight(i)) '%']) ;
   text(i+0.1,water(i)-1,[num2str(100*(spann(i)-water(i))/water(i)) '%']) ;
end

hold off
box  off
end





