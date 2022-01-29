def safeSequence(process,resource,allocation,max,work,need):
   
    f = [0]*process
    ans = [0]*process
    ind = 0
    for k in range(process):
        for i in range(process):
            if(f[i] == 0):
                flag=0
                for j in range(resource):
                    if need[i][j]>work[j]:
                        flag=1
                        break

                if flag==0:
                    ans[ind]=i
                    ind += 1
                    for y in range(resource):                    
                        work[y] += allocation[i][y]
                    f[i]=1

    safe=0
    for i in f:
        if i != 1:
            safe=1
    if(safe==1):
        print("System is not in safe State")
    else:
        print("Following is the SAFE Sequence")

        for i in range(process - 1):
            print(" P", ans[i], " ->", sep="", end="")
        print(" P", ans[process - 1], sep="")

##############################################################################    

process = 5
resource = 3
allocation = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]]

max = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]]

available = [3, 3, 2]
work=[]
work.extend(available)
need = [[0 for i in range(resource)]for i in range(process)]
for i in range(process):
    for j in range(resource):
        need[i][j] = max[i][j]-allocation[i][j]
print(need)
print(available)
safeSequence(process,resource,allocation,max,work,need)
print(available)
while True:

    a=input("Enter 'r' or request and 'e' for exit the program: ")

    if a=='e':
        print("program end")
        break

    if a=='r':
        requested=[]
        Rprocess=int(input("enter which process is to be requested: P"))

        print("enter the resource to be requested")
        for i in range(resource):
            requested.append(int(input()))

        k=0
        print(available)
        for i in range(resource):
            if(requested[i]>available[i]):
                k=1
                print("request granted is not possible due to available resource")
                break
            if requested[i]>need[Rprocess][i]:
                k=1
                print("request granted is not possible due to need resource")
                break
            
        print(available)
        print(allocation)
        print(need) 

        if(k==0):
            for i in range(resource):
                available[i]=available[i]-requested[i]
                allocation[Rprocess][i]=allocation[Rprocess][i]+requested[i]
                need[Rprocess][i]=need[Rprocess][i]-requested[i]
            work.clear()
            work.extend(available)
            print(available)
            print(allocation)
            print(need)

            safeSequence(process,resource,allocation,max,work,need)
