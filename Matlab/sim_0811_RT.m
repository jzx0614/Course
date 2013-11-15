clear all;
colordef white

map_avg_num=10;
testcase = 'Rt';

%testcase = 'Number';
%testcase = 'Cluster';



index =1;
for rt_group = 1 : 5
    for map_id = 1 : map_avg_num
        filename = [testcase '\node_weight\' num2str(map_id) '_' num2str(rt_group) '_map_deployment.txt'];
        fid = fopen(filename);
        fgetl(fid);fgetl(fid);
        node_weight_all(index)=fscanf(fid,'sensor num= %d');
        fclose(fid);

        filename_2 = [testcase '\spann\' num2str(map_id) '_' num2str(rt_group) '_map_deployment.txt'];
        fid_2 = fopen(filename_2);
        fgetl(fid_2);fgetl(fid_2);
        spann_all(index)=fscanf(fid_2,'sensor num= %d');
        fclose(fid_2); 

        filename_3 = [testcase '\water\' num2str(map_id) '_' num2str(rt_group) '_map_deployment.txt'];
        fid_3 = fopen(filename_3);    
        fgetl(fid_3);fgetl(fid_3);
        water_all(index)=fscanf(fid_3,'sensor num= %d');
        fclose(fid_3);         

        filename_4 = [testcase '\all_spann\' num2str(map_id) '_' num2str(rt_group) '_map_deployment.txt'];
        fid_4 = fopen(filename_4);    
        fgetl(fid_4);fgetl(fid_4);
        a_spann_all(index)=fscanf(fid_4,'sensor num= %d');
        fclose(fid_4);         

        filename_5 = [testcase '\msc_node_weight\' num2str(map_id) '_' num2str(rt_group) '_map_deployment.txt'];
        fid_5 = fopen(filename_5);
        fgetl(fid_5);fgetl(fid_5);
        msc_node_weight_all(index)=fscanf(fid_5,'sensor num= %d');
        fclose(fid_5);   
        
        filename_6 = [testcase '\msc_water\' num2str(map_id) '_' num2str(rt_group) '_map_deployment.txt'];
        fid_6 = fopen(filename_6);    
        fgetl(fid_6);fgetl(fid_6);
        msc_water_all(index)=fscanf(fid_6,'sensor num= %d');
        fclose(fid_6);         
        index = index + 1;
    end
end

node_weight(1:(length(node_weight_all)/map_avg_num))=0;
spann(1:(length(node_weight_all)/map_avg_num))=0;
water(1:(length(node_weight_all)/map_avg_num))=0;
a_spann(1:(length(node_weight_all)/map_avg_num))=0;  
msc_node_weight(1:(length(msc_node_weight_all)/map_avg_num))=0;
msc_water(1:(length(node_weight_all)/map_avg_num))=0;

for i = 1 : (length(node_weight_all)/map_avg_num)
    for j = 0 : (map_avg_num-1)
        node_weight(i)  =   node_weight(i) + node_weight_all((i-1)*map_avg_num+1+j);
        spann(i)        =   spann(i) + spann_all((i-1)*map_avg_num+1+j);
        water(i)        =   water(i) + water_all((i-1)*map_avg_num+1+j);
        a_spann(i)      =   a_spann(i) + a_spann_all((i-1)*map_avg_num+1+j); 
        msc_node_weight(i)  =   msc_node_weight(i) + msc_node_weight_all((i-1)*map_avg_num+1+j);
        msc_water(i)        =   msc_water(i) + msc_water_all((i-1)*map_avg_num+1+j);
    end
end

for i = 1 : (length(node_weight_all)/map_avg_num)
    node_weight(i)=node_weight(i)/map_avg_num;
    spann(i)=spann(i)/map_avg_num;
    water(i)=water(i)/map_avg_num;
    a_spann(i)=a_spann(i)/map_avg_num; 
    msc_node_weight(i)=msc_node_weight(i)/map_avg_num;
    msc_water(i)=msc_water(i)/map_avg_num;
end



out_filename = [num2str(testcase) '_result.csv'];
fout = fopen(out_filename,'w');
fprintf(fout,'\r\nall+spanning,');
fprintf(fout,'%d,',a_spann);
fprintf(fout,'\r\nspanning,');
fprintf(fout,'%d,',spann);
fprintf(fout,'\r\nmsc+node_weight,');
fprintf(fout,'%d,',msc_node_weight);
fprintf(fout,'\r\nmsc+water,');
fprintf(fout,'%d,',msc_water);    
fprintf(fout,'node_weight,');
fprintf(fout,'%d,',node_weight);    
fprintf(fout,'\r\nwater,');
fprintf(fout,'%d,',water);

fprintf(fout,'\r\nall+spanning,');
fprintf(fout,'%d,',a_spann_all);
fprintf(fout,'\r\nspanning,');
fprintf(fout,'%d,',spann_all);
fprintf(fout,'\r\nmsc+node_weight,');
fprintf(fout,'%d,',msc_node_weight_all);
fprintf(fout,'\r\nmsc_water,');
fprintf(fout,'%d,',msc_water_all);    
fprintf(fout,'\r\nnode_weight,');
fprintf(fout,'%d,',node_weight_all);    
fprintf(fout,'\r\nwater,');
fprintf(fout,'%d,',water_all);    
fclose(fout);


plot(a_spann,'k^-');        hold on
plot(spann,'msquare--');    hold on    
plot(msc_node_weight,'g>-');hold on
%plot(msc_water,'yo-.');     hold on
plot(node_weight,'r*:');    hold on
%plot(water,'bx-.');         hold on



%legend('Relay Node','MSC-RNP','MSC-NW','MSC-WR','Graph Aided','WaterRipple');
legend('Relay Node','MSC-RNP','MSC-NW','Graph Aided');
xlabel('RT');
ylabel('Number of sensor');

for i = 1 : length(node_weight)
   text(i+0.1,node_weight(i)-2,[num2str(100*(a_spann(i)-node_weight(i))/node_weight(i)) '%']) ;
%   text(i+0.1,water(i)-2,[num2str(100*(a_spann(i)-water(i))/water(i)) '%']) ;
   text(i+0.1,spann(i)+2,[num2str(100*(a_spann(i)-spann(i))/spann(i)) '%']) ;
   text(i+0.1,msc_node_weight(i),[num2str(100*(a_spann(i)-msc_node_weight(i))/msc_node_weight(i)) '%']) ;
%   text(i+0.1,msc_water(i)-2,[num2str(100*(a_spann(i)-msc_water(i))/msc_water(i)) '%']) ;
end

hold off
box  off






