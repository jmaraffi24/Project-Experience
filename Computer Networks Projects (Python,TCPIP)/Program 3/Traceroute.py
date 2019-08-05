import array

f = open("windump.txt", "r")

output = []
request = []
response = []
packet = ""
f1 = f.readlines()
for x in f1:
    if x[0] == " ":
        packet += x
    elif x[0].isdigit() and packet != "":
        output.append(packet)
        packet = x
    else:
        packet = x

for x in output:
    split = x.split()
    if len(split) >= 14 and split[14] == "UDP," and split[7] != "0,":
        request.append(x)
    if len(split) >= 14 and split[14] == "ICMP":
        response.append(x)
print("Request:")
print(request)
print("Response:")
print(response)
requestTTL = []
requestTime = []
responseTTL = []
responseTime=[]
responseIP = []
#print("Request Packets: \n")
for x in request:
    split = x.split()
    requestTTL.append(split[5].replace(",", ""))
    requestTime.append(split[0].replace(":", ""))

#print("Response Packets: \n")
for x in response:
    split = x.split()
    
    responseTTL.append(split[32].replace(",", ""))
    responseTime.append(split[0].replace(":", ""))
    responseIP.append(split[17])

timeDifference = []
f.close()
f = open("output.txt", "w")

TTL = len(responseTTL)/3 - 1
count = 0
count1 = 0
TTLstart = 0


while TTLstart <= TTL:
    count2 = 0
    header = "TTL " + str(TTLstart + 1)
    f.write(header + "\n")
    f.write(responseIP[count1] + "\n")
    count1 += 1
    while count2 < 3:
        if (responseTTL[count] == requestTTL[count]):
            time = (float(responseTime[count]) - float(requestTime[count])) * 1000
            time = str(time) + " ms\n"
            f.write(time)
            count += 1
            count2 += 1
    TTLstart += 1
    f.write("\n")

f.close()
