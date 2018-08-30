n,v=input().split(" ")
n=int(n)
v=int(v)
veh=[]
carry_cap=[]
sorted_veh=[]
sorted_carry_cap=[]
ratio=[]


for i in range(0,n):
    
    a,b=input().split(" ")
    a=int(a)
    b=int(b)
    veh.append(a)
    carry_cap.append(b)
    ratio.append(carry_cap[i]/veh[i])
    sorted_carry_cap.append(0)
    sorted_veh.append(0)


temp_ratio=list(ratio)
sorted_ratio=sorted(ratio,reverse=True)
sorted_carry_rev=sorted(sorted_carry_cap,reverse=True)
for i in range(0,n):
    index=ratio.index(sorted_ratio[i])
    sorted_carry_cap[i]=carry_cap[index]
    sorted_veh[i]=veh[index]
    ratio[index]=-1

max_cap=0
queue=-1
seq=[]
ratio=list(temp_ratio)
# print(sorted_ratio)
# print(sorted_veh)
for i in range(0,n):
    if(v==0):
        break
    if(v>=sorted_veh[i]):
        if(v%2==0):
            if(sorted_veh[i]%2==1):
                if(queue!=-1):
                    temp=queue
                    queue=-1
                    if(v>=sorted_veh[temp]):
                        
                        v-=sorted_veh[temp]
                        
                        max_cap+=sorted_carry_cap[temp]
                        #print(sorted_carry_cap[temp],ratio,"selected")
                        ind=ratio.index(sorted_ratio[temp])
                        seq.append(ind+1)
                        ratio[ind]=-1
                        
                        #print("first queue element entry ",sorted_veh[temp],sorted_carry_cap[temp],max_cap)
                    if(v>=sorted_veh[i]):
                        
                        v-=sorted_veh[i]
                        max_cap+=sorted_carry_cap[i]
                        ind=ratio.index(sorted_ratio[i])
                        seq.append(ind+1)
                        ratio[ind]=-1
                        #print(ind+1,sorted_carry_cap[i],ratio,"selected")
                        #print("second queue element entry ",sorted_veh[i],sorted_carry_cap[i],max_cap)
                else:queue=i
            # if(sorted_veh[i]%2==0):
            else:
                if(v>=sorted_veh[i]):
                    
                    v-=sorted_veh[i]
                    max_cap+=sorted_carry_cap[i]
                    ind=ratio.index(sorted_ratio[i])
                    seq.append(ind+1)
                    ratio[ind]=-1
                    #print(ind+1,sorted_carry_cap[i],ratio,"selected")
                    #print("even element",sorted_veh[i],sorted_carry_cap[i],max_cap)
        else:
            if(v>=sorted_veh[i]):
                v-=sorted_veh[i]
                max_cap+=sorted_carry_cap[i]
                ind=ratio.index(sorted_ratio[i])
                seq.append(ind+1)
                ratio[ind]=-1
                #print(ind+1,sorted_carry_cap[i],ratio,"selected")
                #print("odd v",sorted_veh[i],sorted_carry_cap[i],max_cap)

print(max_cap)
string=""
for i in seq:
    print(i)


