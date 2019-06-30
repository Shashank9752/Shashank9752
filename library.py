import pymysql
con=pymysql.connect(host="locathost",user="shashank",passwd="shashank")
mycursor=con.cursor()
def addbookdetails():
  bookid=input("Enter book id=")
  title=input("Enter book title=")
  sub=input("Enter book subject=")
  author=input("Enter book author=")
  status=input("Enter book status(avail)=")
  sql="insert into book values('"+bookid+"','"+title+"','"+sub+"','"+author+"','"+status+"')"
  mycursor.execute(sql)
  print("Book details updated")


def deletebook():
   bookid=input("Enter book-id to be deleted=")
   sql="delete from book where Bookid='"+bookid+"'"
   mycursor.execute(sql)
   print("Book deleted")

def viewbook():
   sql="select * from book"
   mycursor.execute(sql)
   for row in mycursor.fetchall():
        print(row[0],row[1],row[2],row[3],row[4])

def searchbook():
   bookid=input("Enter the book-id to be searched=")
   sql="select * from book where Bookid='"+bookid+"'"
   mycursor.execute(sql)
   count=0
   for i in mycursor.fetchall():
      count=count+1
   if count==0:
      print("Book not present")
   else:         
      for j in mycursor.fetchall():
           print(j[0],j[1],j[2],j[3],j[4])

def issuebook():
   bookid=input("Enter book-id")
   sub=input("Enter subject of book =")
   av="avail"
   uav="unavail"
   sql="update book set status='"+uav+"'where Bookid'"+bookid+"'"
   mycursor.execute(sql)
   print("Updation successfull")


def empregi():
   empid=input("Enter the Employe ID=")
   name=input("Enter the Employe name=")
   dep=input("Enter the department=")
   doj=input("Enter the Date of joining=")
   salary=input("Enter the salary=")
   sql="insert into employe values'"+empid+"','"+name+"','"+dep+"','"+doj+"','"+salary+"')"
   mycursor.execute(sql)
   print("**********Registration successfull************")
def emplogin():
   name=input("Enter the name of Employe=")
   empid=input("Enter the ID of Employee=")
   sql=="select * from employe where Name='"+name+"'and Empid'"+empid+"'"
   if mycursor.execute(sql):
      print("********Login Successfull***********")
      print("Menu \n 1.Add book details\n2.Delete book from record\n3.view book list\n4.search book\n5.issue book to student")
      emp=eval(input("Enter ur choice="))
      if emp==1:
         addbookdetails()
      if emp==2:
         deletebook()
      if emp==3:
         viewbook()
      if emp==4:
         searchbook()
      if emp==5:
         issuebook()
   else:
       print("***********Login Unsuccessfull***********")
def studentregi():
    roll=input("Enter ur roll no.")
    name=input("Enter ur name")
    dept=input("Enter ur department")
    sem=input("Enter ur semester")
    batch=input("Enter ur batch")
    sql="insert into student values('"+roll+"','"+name+"','"+dept+"','"+sem+"','"+batch+"'"
    print("Registration successfull")

def studentlogin():
    name=input("Enter student name=")
    roll=input("Enter student roll no.")
    sql="select * from student where Name='"+name+"' and Rollno='"+roll+"'"
    if mycursor.execute(sql):
        print("************Login Successfull***********")
        print("Menu \n 1.View book list\n 2.search book")
        st=input("Enter ur choice")
        if st==1:
            viewbook()
        if st==2:
            searchbook()
    else:
        print("**************Login unsuccessfull**********")   
def student():
   while True:
      print("1.Register \n 2.Login \n 3.Exit")
      y=eval(input("Enter ur choice"))
      if y==1:
         studentregi()
      if y==2:
         studentlogin()
      if y==3:
         exit()
def employe():
   while True:
      print("1.Registration \n 2.Login\n3.Exit")
      z=eval(input("Enter ur choice"))
      if z==1:
          empregi()
      if z==2:
          emplogin()
      if z==3:
          exit()

while True:
   print("-------------------------------------------")
   print("-----------------Library-------------------")
   print("1.Student\n 2.Employee\n 3.Exit")
   x=eval(input("Enter ur choice"))
   if x==1:
      student()
   if x==2:
      employe()
   if x==3:
      exit()

con.commit()
con.close()


