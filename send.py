#!/usr/bin/env python
import pika
import random

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')

recycling_facts = []
recycling_facts.append("More than 52 million tons of paper products were recycled in 2018. That's roughly the same weight as almost 350,000 blue whales.")
recycling_facts.append("Over 24 trillion Styrofoam coffee cups are thrown away each year.")
recycling_facts.append("On average, each one of us produces 4.4 pounds of solid waste each day.")
recycling_facts.append("If all our newspaper was recycled, we could save 250,000,000 trees each year.")
recycling_facts.append("In the US we use 2,500,000 plastic bottles every hour.")
recycling_facts.append("There is no limit to the amount of times a can made from aluminum can be recycled.")
recycling_facts.append("We generate 21.5 million tons of food waste each year.")

for i in range(7):
    temp = random.choice(recycling_facts)


channel.basic_publish(exchange='',
                      routing_key='hello',
                      body='A Message from CS361.')
print("Recycling Fact: ", temp)


connection.close()