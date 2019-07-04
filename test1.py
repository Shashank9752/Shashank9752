from tkinter import messagebox as mb
import sqlite3
con=sqlite3.connect("library")
mycursor=con.cursor()
from tkinter import *
a=Tk()
a.title("LIBRARY")
a.geometry("300x300")
homeframe=Frame(a)
adminframe=Frame(a)
adminlogframe=Frame(a)
adminregi=Frame(a)
studentframe=Frame(a)
studentlogin=Frame(a)
studentregi=Frame(a)
dataadminregi=Frame(a)
datainstadmin=Frame(a)
def student():
    def studentlogin():
        studentframe.destroy()
        global studentlogin,studentregi
        Label(studentlogin,text="STUDENT LOGIN").grid(row=0,column=1,columnspan=2)
        Label(studentlogin, text="Enter name:").grid(row=1, column=1)
        Label(studentlogin, text="Enter password").grid(row=2, column=1)
        Entry(studentlogin).grid(row=1,column=2)
        Entry(studentlogin,show="*").grid(row=2,column=2)
        Button(studentlogin,text="LOGIN").grid(row=3,column=1)
        Button(studentlogin,text="EXIT",command=quit).grid(row=3,column=2)
        studentlogin.pack()
    def studentregi():
        studentframe.destroy()
        global studentlogin,studentlogin
        Label(adminregi, text="STUDENT REGISTRATION").grid(row=0, column=1, columnspan=2)
        Label(adminregi, text="Enter roll no.:").grid(row=1, column=1)
        Label(adminregi, text="Enter name:").grid(row=2, column=1)
        Label(adminregi, text="Enter department:").grid(row=3, column=1)
        Label(adminregi, text="Enter semester:").grid(row=4, column=1)
        Label(adminregi, text="Enter batch:").grid(row=5, column=1)
        Entry(adminregi).grid(row=1, column=2)
        Entry(adminregi).grid(row=2, column=2)
        Entry(adminregi).grid(row=3, column=2)
        Entry(adminregi).grid(row=4, column=2)
        Entry(adminregi).grid(row=5, column=2)
        Button(adminregi, text="REGISTER").grid(row=6, column=1)
        Button(adminregi, text="CANCEL", command=quit).grid(row=6, column=2)
        adminregi.pack()
    homeframe.destroy()
    Label(studentframe,text="WELLCOME TO STUDENT SECTION").grid(row=0,column=0,columnspan=2)
    Button(studentframe,text="Login",command=studentlogin).grid(row=1,column=0,columnspan=2)
    Button(studentframe,text="Register",command=studentregi).grid(row=2,column=0,columnspan=2)
    Button(studentframe,text="Exit",command=quit).grid(row=3,column=0,columnspan=2)
    studentframe.pack()
def admin():
    def adminlogin():
        global a,b
        a=StringVar()
        b=StringVar()
        def dataadminlogin():
            name=a.get()
            id=b.get()
            sql="select * from admin where idno='"+id+"'and name='"+name+"'"
            mycursor.execute(sql)
            count = 0
            for row in mycursor:
                count = count + 1
            if (count > 0):
                datainstadmin.destroy()
                mb.showinfo("Login status","Login Successfull")
                adminbutton()
                '''Label(datainstadmin,text="ADMIN BLOCK").grid(row=0,column=1,columnspan=2)
                Button(datainstadmin,text="View books").grid(row=1,column=2)
                Button(datainstadmin,text="Add new book").grid(row=2,column=2)
                Button(datainstadmin,text="Delete book").grid(row=3,column=2)
                Button(datainstadmin,text="Search book").grid(row=4,column=2)
                Button(datainstadmin,text="Issue book").grid(row=5,column=2)
                Button(datainstadmin,text="EXIT").grid(row=6,column=3)
                datainstadmin.pack()'''
                '''sql="create table if not exists book(bookid varchar primary key,title varchar,sub varchar,author varchar,status varchar)"
                Label(datainstadmin,text="BOOK DETAILS").grid(row=0,column=1,columnspan=2)
                mycursor.execute(sql)'''






            else:
                mb.showinfo("Login status","Login fail")
            con.commit()

        adminframe.destroy()
        Label(adminlogframe,text="ADMIN LOGIN").grid(row=0,column=1,columnspan=2)
        Label(adminlogframe,text="Enter name:").grid(row=1,column=1)
        Label(adminlogframe,text="Enter ID no.:").grid(row=2,column=1)
        Entry(adminlogframe,textvariable=a).grid(row=1,column=2)
        Entry(adminlogframe,textvariable=b,show="*").grid(row=2,column=2)
        Button(adminlogframe,text="Login",command=dataadminlogin).grid(row=3,column=1)
        Button(adminlogframe,text="cancel",command=quit).grid(row=3,column=2)
        adminlogframe.pack()
    def adminregi():
        adminframe.destroy()
        global a,b,c,d,e
        a=StringVar()
        b=StringVar()
        c=StringVar()
        d=StringVar()
        e=StringVar()
        global adminregi
        def dataadminregi():
            id=a.get()
            name=b.get()
            dept=c.get()
            doj=d.get()
            sal=e.get()
            sql="create table if not exists admin(idno varchar primary key,name varchar,dept varchar,doj varchar,salary varchar)"
            mycursor.execute(sql)
            sql="insert into admin values('"+id+"','"+name+"','"+dept+"','"+doj+"','"+sal+"')"
            mycursor.execute(sql)
            mb.showinfo("Registration Successfull","your hav successfully registered")
            con.commit()
            con.close()

        Label(adminregi,text="ADMIN REGISTRATION").grid(row=0,column=1,columnspan=2)
        Label(adminregi,text="Enter ID No.:").grid(row=1,column=1)
        Label(adminregi,text="Enter name:").grid(row=2,column=1)
        Label(adminregi,text="Enter department:").grid(row=3,column=1)
        Label(adminregi,text="Enter date of join:").grid(row=4,column=1)
        Label(adminregi,text="Enter salary:").grid(row=5,column=1)
        Entry(adminregi,textvariable=a).grid(row=1,column=2)
        Entry(adminregi,textvariable=b).grid(row=2,column=2)
        Entry(adminregi,textvariable=c).grid(row=3,column=2)
        Entry(adminregi,textvariable=d).grid(row=4,column=2)
        Entry(adminregi,textvariable=e).grid(row=5,column=2)
        Button(adminregi,text="REGISTER",command=dataadminregi).grid(row=6,column=1)
        Button(adminregi,text="CANCEL",command=quit).grid(row=6,column=2)
        adminregi.pack()
    global adminframe,studentframe
    homeframe.destroy()
    Label(adminframe,text="WELLCOME TO ADMIN SECTION").grid(row=0,column=1,columnspan=2)
    Button(adminframe,text="LOGIN",command=adminlogin).grid(row=1,column=1,columnspan=2)
    Button(adminframe,text="REGISTER",command=adminregi).grid(row=2,column=1,columnspan=2)
    Button(adminframe,text="EXIT",command=quit).grid(row=3,column=1,columnspan=2)
    adminframe.pack()
Label(homeframe,text="WELLCOME TO LIBRARY").grid(row=0,column=1,columnspan=2)
Button(homeframe,text="ADMIN",command=admin).grid(row=1,column=1)
Button(homeframe,text="STUDENT",command=student).grid(row=1,column=2)
Button(homeframe,text="EXIT",command=quit).grid(row=3,column=1,columnspan=2)
homeframe.pack()

a.mainloop()
