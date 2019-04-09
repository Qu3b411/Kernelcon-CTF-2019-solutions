---
title: "I did a test run on this thing it took me twenty minutes"
date: "2018-09-12T17:17:09.000Z"
layout: post
draft: false
path: "/posts/misc/"
category: "misc"
tags:
  - "scripting"
  - "misc" 
  - "Timeing Attack" 
description: "Write a script to execute the appropriate side channel attack"
---
# Solution
Side channel attacks exploit flaws in the implementation that enable an attacker to determine patterns
and critical information without actually breaking the algorithm. This particular application is grossly vulnerable to a side channel attack known as a **Timing attack**.

**Timing attack** utilize the differences in time that two paths might take. For instance if the first character of a password is correct it may take a little longer to process then if the first character is wrong. To take advantage of this vulnerability in implementation, one must time various inputs and analize the outcome for outliers,and this also means you must control what is running on your processor. 

### To start
You must have nothing running on your computer. I would suggest when one is ready to exploit the vulnlogin they restart their computer to minimize noise on their linux box. This also limits the potential of that one computer because any interactions with it may interfere with getting the flag.

## to automate the timing portion of the attack a simple bash script may be written as follows: 
 ~~~~
 
 #!bin/bash

chars=(a b c d e f 1 2 3 4 5 6 7 8 9 0)

for k in "${chars[@]}"; do >&2 printf "%s," $k ; (time echo $1$k |  ./SideChanelVulnerableLogin;) 2>&1 | grep real ;sleep 1; done  

~~~~

if you paid attention to the characters mentioned in the challange, you may have guessed the kernel flag is the valid input. Knowing the format of the flag is **kernel{md5}** you could take the character set provided **{0-9},{a-f},k,r,n,l,'}','{'**  and remove all but **{0-9},{a-f}**, so this is what you should have done. This challange is designed to steal one of your teams computers for a while and make it unusable for other challanges while you sit and stare at your computer. A more sophisticated solution may have been to isolate one processor core and use statistical analysis to aquire the flag; however, this is not needed. The solution written below was done in user mode on a gui with the minimal bash written above. The sleep is to allow the linux kernel to accomplish low priority tasks without forcing the application to change processes and mess with your timing,but as you will see, higher priority tasks sometimes come online and are scheduled onto the processor. This will result in a false positive. A few instances of false positives exist as seen below!

## The attack will appear as follows.
**Ding it manually allows you to make decisions that would otherwise requre statistical analysis**
The rest of the automation is up to you if you want to further automate the attack. This is the bare bones form of the attack. the result is as follows! 
~~~~
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{
a,real	0m1.269s
b,real	0m1.240s
c,real	0m1.257s
d,real	0m1.235s
e,real	0m1.449s
f,real	0m1.246s
1,real	0m1.262s
2,real	0m1.267s
3,real	0m1.241s
4,real	0m1.282s
5,real	0m1.234s
6,real	0m1.266s
7,real	0m1.246s
8,real	0m1.254s
9,real	0m1.233s
0,real	0m1.266s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e
a,real	0m1.427s
b,real	0m1.442s
c,real	0m1.436s
d,real	0m1.418s
e,real	0m1.421s
f,real	0m1.464s
1,real	0m1.442s
2,real	0m1.633s
3,real	0m1.440s
4,real	0m1.431s
5,real	0m1.440s
6,real	0m1.441s
7,real	0m1.435s
8,real	0m1.431s
9,real	0m1.416s
0,real	0m1.418s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2
a,real	0m1.610s
b,real	0m1.604s
c,real	0m1.795s
d,real	0m1.602s
e,real	0m1.634s
f,real	0m1.597s
1,real	0m1.633s
2,real	0m1.604s
3,real	0m1.607s
4,real	0m1.601s
5,real	0m1.623s
6,real	0m1.605s
7,real	0m1.606s
8,real	0m1.615s
9,real	0m1.646s
0,real	0m1.634s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c
a,real	0m1.811s
b,real	0m1.798s
c,real	0m1.788s
d,real	0m1.821s
e,real	0m1.793s
f,real	0m1.802s
1,real	0m1.785s
2,real	0m1.778s
3,real	0m1.830s
4,real	0m1.784s
5,real	0m1.802s
6,real	0m1.770s
7,real	0m1.973s
8,real	0m1.818s
9,real	0m1.803s
0,real	0m1.784s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7
a,real	0m1.966s
b,real	0m2.188s
c,real	0m1.977s
d,real	0m1.975s
e,real	0m1.957s
f,real	0m1.959s
1,real	0m1.950s
2,real	0m1.943s
3,real	0m1.947s
4,real	0m1.959s
5,real	0m1.980s
6,real	0m1.953s
7,real	0m1.943s
8,real	0m1.950s
9,real	0m1.978s
0,real	0m1.978s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7b
a,real	0m2.126s
b,real	0m2.132s
c,real	0m2.126s
d,real	0m2.142s
e,real	0m2.115s
f,real	0m2.316s
1,real	0m2.149s
2,real	0m2.128s
3,real	0m2.132s
4,real	0m2.148s
5,real	0m2.121s
6,real	0m2.159s
7,real	0m2.146s
8,real	0m2.120s
9,real	0m2.133s
0,real	0m2.151s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf
a,real	0m2.320s
b,real	0m2.331s
c,real	0m2.339s
d,real	0m2.373s
e,real	0m2.287s
f,real	0m2.339s
1,real	0m2.311s
2,real	0m2.318s
3,real	0m2.481s
4,real	0m2.344s
5,real	0m2.329s
6,real	0m2.301s
7,real	0m2.336s
8,real	0m2.310s
9,real	0m2.295s
0,real	0m2.340s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf3
a,real	0m2.483s
b,real	0m2.491s
c,real	0m2.494s
d,real	0m2.489s
e,real	0m2.500s
f,real	0m2.520s
1,real	0m2.500s
2,real	0m2.499s
3,real	0m2.696s
4,real	0m2.483s
5,real	0m2.482s
6,real	0m2.470s
7,real	0m2.471s
8,real	0m2.511s
9,real	0m2.479s
0,real	0m2.489s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf33
a,real	0m2.718s
b,real	0m2.668s
c,real	0m2.689s
d,real	0m2.672s
e,real	0m2.680s
f,real	0m2.858s
1,real	0m2.680s
2,real	0m2.669s
3,real	0m2.664s
4,real	0m2.665s
5,real	0m2.669s
6,real	0m2.855s
7,real	0m2.669s
8,real	0m2.685s
9,real	0m2.701s
0,real	0m2.656s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf33f
a,real	0m2.669s
b,^C
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336
a,real	0m2.835s
b,real	0m2.864s
c,real	0m2.856s
d,real	0m2.826s
e,real	0m2.838s
f,real	0m2.858s
1,real	0m2.873s
2,real	0m2.856s
3,real	0m2.863s
4,real	0m2.845s
5,real	0m2.832s
6,real	0m2.833s
7,real	0m3.085s
8,real	0m2.852s
9,real	0m2.865s
0,real	0m2.866s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf3367
a,real	0m3.028s
b,real	0m3.005s
c,real	0m3.028s
d,real	0m3.036s
e,real	0m3.031s
f,real	0m3.029s
1,real	0m3.032s
2,real	0m3.020s
3,real	0m3.030s
4,real	0m3.007s
5,real	0m3.020s
6,real	0m3.182s
7,real	0m3.023s
8,real	0m3.019s
9,real	0m3.033s
0,real	0m3.005s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf33676
a,real	0m3.199s
b,real	0m3.178s
c,real	0m3.165s
d,real	0m3.211s
e,real	0m3.232s
f,real	0m3.290s
1,real	0m3.262s
2,real	0m3.273s
3,real	0m3.209s
4,real	0m3.181s
5,real	0m3.198s
6,real	0m3.213s
7,real	0m3.391s
8,real	0m3.193s
9,real	0m3.193s
0,real	0m3.208s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767
a,real	0m3.381s
b,real	0m3.366s
c,real	0m3.372s
d,real	0m3.367s
e,real	0m3.461s
f,real	0m3.383s
1,real	0m3.364s
2,real	0m3.359s
3,real	0m3.443s
4,real	0m3.369s
5,real	0m3.384s
6,real	0m3.363s
7,real	0m3.390s
8,real	0m3.554s
9,real	0m3.375s
0,real	0m3.396s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf3367678
a,real	0m3.560s
b,real	0m3.523s
c,real	0m3.539s
d,real	0m3.655s
e,real	0m3.610s
f,real	0m3.755s
1,real	0m3.563s
2,real	0m3.723s
3,real	0m3.583s
4,real	0m3.525s
5,real	0m3.552s
6,real	0m3.550s
7,real	0m3.551s
8,real	0m3.564s
9,real	0m3.550s
0,real	0m3.619s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf3367678f
a,real	0m3.534s
b,^C
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf33676782
a,real	0m3.725s
b,real	0m3.746s
c,real	0m3.742s
d,real	0m3.701s
e,real	0m3.801s
f,real	0m3.733s
1,real	0m3.728s
2,real	0m3.722s
3,real	0m3.713s
4,real	0m3.757s
5,real	0m3.702s
6,real	0m3.716s
7,real	0m3.729s
8,real	0m3.915s
9,real	0m3.732s
0,real	0m3.725s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828
a,real	0m3.881s
b,real	0m3.913s
c,real	0m3.903s
d,real	0m3.916s
e,real	0m3.880s
f,real	0m3.886s
1,real	0m3.894s
2,real	0m3.903s
3,real	0m3.928s
4,real	0m3.892s
5,real	0m3.907s
6,real	0m3.997s
7,real	0m3.926s
8,real	0m3.925s
9,real	0m4.099s
0,real	0m3.918s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf3367678289
a,real	0m4.098s
b,real	0m4.091s
c,real	0m4.134s
d,real	0m4.068s
e,real	0m4.079s
f,real	0m4.092s
1,real	0m4.080s
2,real	0m4.078s
3,real	0m4.258s
4,real	0m4.091s
5,real	0m4.093s
6,real	0m4.096s
7,real	0m4.103s
8,real	0m4.064s
9,real	0m4.147s
0,real	0m4.098s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf33676782893
a,real	0m4.259s
b,real	0m4.264s
c,real	0m4.277s
d,real	0m4.248s
e,real	0m4.268s
f,real	0m4.260s
1,real	0m4.457s
2,real	0m4.300s
3,real	0m4.283s
4,real	0m4.267s
5,real	0m4.280s
6,real	0m4.254s
7,real	0m4.234s
8,real	0m4.266s
9,real	0m4.261s
0,real	0m4.240s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931
a,real	0m4.399s
b,real	0m4.439s
c,real	0m4.620s
d,real	0m4.416s
e,real	0m4.419s
f,real	0m4.440s
1,real	0m4.421s
2,real	0m4.443s
3,real	0m4.464s
4,real	0m4.415s
5,real	0m4.414s
6,real	0m4.430s
7,real	0m4.437s
8,real	0m4.446s
9,real	0m4.434s
0,real	0m4.436s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c
a,real	0m4.606s
b,real	0m4.607s
c,real	0m4.623s
d,real	0m4.603s
e,real	0m4.606s
f,real	0m4.623s
1,real	0m4.599s
2,real	0m4.616s
3,real	0m4.736s
4,real	0m4.605s
5,real	0m4.673s
6,real	0m4.584s
7,real	0m4.779s
8,real	0m4.633s
9,real	0m4.622s
0,real	0m4.589s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7
a,real	0m4.800s
b,real	0m4.784s
c,real	0m4.777s
d,real	0m4.783s
e,real	0m4.785s
f,real	0m4.820s
1,real	0m4.783s
2,real	0m4.804s
3,real	0m4.789s
4,real	0m4.779s
5,real	0m4.798s
6,real	0m4.803s
7,real	0m4.962s
8,real	0m4.768s
9,real	0m4.773s
0,real	0m4.854s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c77
a,real	0m4.981s
b,real	0m4.985s
c,real	0m4.933s
d,real	0m4.951s
e,real	0m4.945s
f,real	0m4.960s
1,real	0m4.965s
2,real	0m4.972s
3,real	0m4.958s
4,real	0m4.996s
5,real	0m5.147s
6,real	0m4.942s
7,real	0m4.959s
8,real	0m4.986s
9,real	0m4.961s
0,real	0m4.982s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c775
a,real	0m5.126s
b,real	0m5.171s
c,real	0m5.152s
d,real	0m5.192s
e,real	0m5.159s
f,real	0m5.180s
1,real	0m5.125s
2,real	0m5.200s
3,real	0m5.131s
4,real	0m5.155s
5,real	0m5.129s
6,real	0m5.119s
7,real	0m5.141s
8,real	0m5.117s
9,real	0m5.139s
0,real	0m5.315s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750
a,real	0m5.299s
b,real	0m5.321s
c,real	0m5.475s
d,real	0m5.309s
e,real	0m5.337s
f,real	0m5.330s
1,real	0m5.382s
2,real	0m5.333s
3,real	0m5.320s
4,real	0m5.316s
5,real	0m5.326s
6,real	0m5.706s
7,real	0m5.288s
8,real	0m5.318s
9,real	0m5.330s
0,real	0m5.300s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c77506
a,real	0m5.309s
b,^C
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750c
a,real	0m5.497s
b,real	0m5.478s
c,real	0m5.497s
d,real	0m5.489s
e,real	0m5.510s
f,real	0m5.679s
1,real	0m5.495s
2,real	0m5.494s
3,real	0m5.507s
4,real	0m5.481s
5,real	0m5.509s
6,real	0m5.494s
7,real	0m5.516s
8,real	0m5.506s
9,real	0m5.492s
0,real	0m5.501s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cf
a,real	0m5.693s
b,real	0m5.690s
c,real	0m5.692s
d,real	0m5.661s
e,real	0m5.847s
f,real	0m5.677s
1,real	0m5.683s
2,real	0m5.658s
3,real	0m5.655s
4,real	0m5.659s
5,real	0m5.696s
6,real	0m5.648s
7,real	0m5.682s
8,real	0m5.721s
9,real	0m5.673s
0,real	0m5.679s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cfe
a,real	0m5.929s
b,real	0m5.906s
c,real	0m5.873s
d,real	0m5.886s
e,real	0m5.820s
f,real	0m5.828s
1,real	0m5.815s
2,real	0m5.840s
3,real	0m6.035s
4,real	0m5.874s
5,real	0m5.857s
6,real	0m5.826s
7,real	0m5.866s
8,real	0m5.848s
9,real	0m5.851s
0,real	0m5.847s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cfe3
a,real	0m6.144s
b,real	0m6.027s
c,real	0m6.042s
d,real	0m6.033s
e,real	0m6.046s
f,real	0m6.006s
1,real	0m6.202s
2,real	0m6.008s
3,real	0m6.014s
4,real	0m6.004s
5,real	0m6.050s
6,real	0m6.045s
7,real	0m6.052s
8,real	0m5.992s
9,real	0m6.031s
0,real	0m6.032s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cfe31
a,real	0m6.193s
b,real	0m6.218s
c,real	0m6.203s
d,real	0m6.445s
e,real	0m6.208s
f,real	0m6.185s
1,real	0m6.205s
2,real	0m6.185s
3,real	0m6.215s
4,real	0m6.172s
5,real	0m6.226s
6,real	0m6.202s
7,real	0m6.309s
8,real	0m6.196s
9,real	0m6.172s
0,real	0m6.211s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cfe31d
a,real	0m6.381s
b,real	0m6.474s
c,real	0m6.358s
d,real	0m6.454s
e,real	0m6.582s
f,real	0m6.369s
1,real	0m6.360s
2,real	0m6.363s
3,real	0m6.349s
4,real	0m6.400s
5,real	0m6.393s
6,real	0m6.388s
7,real	0m6.386s
8,real	0m6.378s
9,real	0m6.381s
0,real	0m6.377s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cfe31de
a,real	0m6.536s
b,real	0m6.583s
c,real	0m6.714s
d,real	0m6.566s
e,real	0m6.552s
f,real	0m6.552s
1,real	0m6.568s
2,real	0m6.575s
3,real	0m6.539s
4,real	0m6.587s
5,real	0m6.542s
6,real	0m6.545s
7,real	0m6.552s
8,real	0m6.714s
9,real	0m6.581s
0,real	0m6.565s
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cfe31dec
a,real	0m6.540s
b,^C
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ bash ./SideChanel.sh  kernel{e2c7bf336767828931c7750cfe31de8
a,real	0m6.694s
b,real	0m6.750s
c,real	0m6.723s
d,real	0m6.735s
e,real	0m6.735s
f,real	0m6.709s
1,real	0m6.885s
2,real	0m6.812s
3,real	0m6.741s
4,real	0m6.818s
5,real	0m6.899s
6,real	0m6.745s
7,real	0m6.752s
8,real	0m6.716s
9,real	0m6.770s
0,real	0m6.813s

kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ echo  kernel{e2c7bf336767828931c7750cfe31de85} | ./SideChanelVulnerableLogin 
Invalid Password!
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ echo  kernel{e2c7bf336767828931c7750cfe31de81} | ./SideChanelVulnerableLogin 
Congratulations!
kodachi@Secure-OS:~/Desktop/CTF/TimingAttack/bin/Release$ 
~~~~
