item=['shirt','jeans','kurta','lungi']
q=[10,20,30,40]
iq=[10,20,30,40]
r=[100,200,300,400]
carti=[]
cartq=[]
rate=[]
while True:
    print("\n1.View item details")
    print("2.add to cart")
    print("3.View cart")
    print("4.remove from cart")
    print("5.invoice")
    print("6.exit")
    x=eval(input("Enter your choice"))
    if(x==1):
         print("Item         Quantity     Rate")
         for i in range(len(item)):
            print("%-15s%-5d%10d"%(item[i],q[i],r[i]))

    if(x==2):
        x=input("Enter the item to buy=")
        y=eval(input("Enter the quantity="))
        if x in item:
            a=item.index(x)
            b=q[a]
            if(y<b):
                if x in carti:
                    p=carti.index(x)
                    cartq[p]=cartq[p]+y
                    q[a]=b-y

                else:
                    carti.append(x)
                    cartq.append(y)
                    q[a]=b-y
                    rate.append(r[a])

            elif y==b:
                carti.append(x)
                cartq.append(y)
                item.remove(x)
                q.remove(q[a])
                r.remove(r[a])
            else:
                print("Entered quantity is not avaliable")
        else:
            print("Entered item is not avaliable")
    if(x==3):
        for i in range(len(carti)):
            print(carti[i],end=" ")
            print(cartq[i],end=" ")

    if(x==4):
        l=input("Enter the item to be removed=")
        m=eval(input("Enter the quantity of item="))
        if l in carti:
            t=carti.index(l)
            e=item.index(l)
            w=cartq[t]
            if m<w:
               cartq[t]=cartq[t]-m
               q[e]=q[e]+m

            elif m==w:
                carti.remove(l)
                cartq.remove(cartq[t])
                rate.remove(rate[t])
                q[e]=q[e]+m
        else:
            print("Entered item is not in cart")
    if(x==5):
        print("ITEM       QUANTITY       MRP")
        print("-----------------------------")
        t=0
        for i in range(len(carti)):
            print("%-15s%-5d%10d"%(carti[i],cartq[i],rate[i]*cartq[i]))
        print("-----------------------------")

        for j in range(len(carti)):
            t=cartq[i]*rate[i]+t

        print("TOTAL                    ",t)







