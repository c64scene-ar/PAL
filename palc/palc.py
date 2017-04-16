#!/usr/bin/python 
import subprocess
import argparse
import sys 
import json

class Palc:
	pass

class Room:
	name = ""
	description = ""
	items = []
	exits = []

	def inflateIL(self, ILObj):
		self.description = ILObj['desc']
		self.name = ILObj['name']
		for item in ILObj['items']:
			itemObj = Item(item['item'], item['desc'], item['actions'])
			self.items.append(itemObj)

		for exit in ILObj['exits']:
			exitObj = Exit(exit['exit'], exit['room'])
			self.exits.append(exitObj)

	def __repr__(self):
		return "Room (%s) %s \n %s %s \n" % (self.name, self.description, self.items, self.exits)
	
class Exit:
	direction = ""
	next_room = ""

	def __init__(self, direction, next_room):
		self.direction = direction
		self.next_room = next_room
	
	def __repr__(self):
		return "\t Exit (%s -> %s)\n " % (self.direction, self.next_room)

class Inventory:
	items = []
	
	def __init__(self, items = []):
		self.items = items

class Action:
	verb  = ""
	tells = ""
	
	def __init__(self, verb, tells):
		self.verb = verb
		self.tells = tells

	def __repr__(self):
		return "\t\t\t Action (%s --> %s)\n" % (self.verb, self.tells)

class Item:
	name = ""
	description = ""
	actions = []

	def __init__(self, name, description, actions = []):
		self.name = name
		self.description = description

		for a in actions:
			actionObj = Action(a['verb'], a['desc'])
			self.actions.append(actionObj)

	def __repr__(self):
		return "\t\t Item (%s) (%s) %s\n" % (self.name, self.description, self.actions)


if __name__ == '__main__':
	print "---------------------------------------"
	print "PALc (Punga Aventura Language compiler)"
	print "alekhin0w/PVM"
	print "---------------------------------------"
	parser = argparse.ArgumentParser(description='palc')

	parser.add_argument('filename', help='Path to .pal file')

	args = parser.parse_args()
	if len(args.filename) > 1:
		# generate Pungas Intermediate Language file (PIL)
		subprocess.check_output(['nodejs', 'IL.js', 'arg2']).split('\n')
		
		ILObj = ""
		with open('living.pil', 'r') as fd:
			ILObj = json.load(fd)

		r = Room()
		r.inflateIL(ILObj)
		print r
		# obtain json object from parsing .pal file
		# and create an inflated Room object 
		
		# use Room object and create C files accordingly

		# include all rooms and connect them

		# compile rooms and engine

		# ???

		# profit! run x64

		sys.exit(0)

