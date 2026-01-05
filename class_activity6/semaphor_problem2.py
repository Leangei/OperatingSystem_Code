from threading import Semaphore, Thread

# Semaphore initialization
a = Semaphore(1)  
b = Semaphore(0)
c = Semaphore(0)  

def Process1():
    a.acquire()
    print("H")
    print("E")
    b.release()

def Process2():
    b.acquire()
    print("L")
    c.release()

def Process3():
    c.acquire()
    print("L")
    print("O")

# Create and start threads
t1 = Thread(target=Process1)
t2 = Thread(target=Process2)
t3 = Thread(target=Process3)

t1.start()
t2.start()
t3.start()

t1.join()
t2.join()
t3.join()
