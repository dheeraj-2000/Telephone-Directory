# -*- coding: utf-8 -*-
"""
Created on Sat Dec  2 14:50:12 2017

@author: SATYAM COMPUTERS
"""


from database import telephone as pl
def display():
     print( 'Number'.ljust(6), ' \t'    'Name'.ljust(18),      'gender',  '\t'     'age')
     for key in pl.keys():
         print (' {}   {} {}  {}'.format(key,pl[key][0].ljust(20),pl[key][1], pl[key][2])) 
from database import telephone as pl         
def p1():
     pin=input("enter the phone number")
     for x in p1:
         if x==pin:
             print(telephone.get(pin))
         else:
             print("number does not exists")