name =[]
burst_time = []
arrival_time = []
finish_time =[]
waiting_time =[]
sum =int(0)
print "Enter the number of processes"
n = input()
print "Enter the Name of the processes"
name = [str(raw_input()) for i in range(n)]
print "Enter the arrival time of the processes"
arrival_time = [int(input()) for i in range(n)]
print "Enter the burst time of the processes"
burst_time = [int(input()) for i in range(n)]
for i in range(n):
    for j in range(n-i-1):
        if(arrival_time[j]>arrival_time[j+1]):
            temp=arrival_time[j]
            arrival_time[j]=arrival_time[j+1]
            arrival_time[j+1]=temp
            temp2=burst_time[j]
            burst_time[j]=burst_time[j+1]
            burst_time[j]=temp2
            temp3=name[j]
            name[j]=name[j+1]
            name[j]=temp3
print "Process Name"+"\t"+"Arrival time"+"\t"+"Burst time"
for i in range(n):
    print name[i],"\t\t\t",arrival_time[i],"\t\t\t\t",burst_time[i]
    finish_time = [int(arrival_time[i] + burst_time[i]) for i in range(n)]
    waiting_time=[int(finish_time[i]-arrival_time[i]) for i in range(n)]
for  i in range(n):
        sum += int(waiting_time[i])
print "waiting time of Process"
for i in range(n):
    print name[i],"\t\t",waiting_time[i]
print "Average waiting time ",sum/n