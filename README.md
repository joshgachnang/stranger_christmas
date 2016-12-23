Stranger Christmas
==================

This was a little project I did to learn how to use an Arduino. I love the Netflix
series Stranger Things. When I saw the [Christmas lights scene](https://www.youtube.com/watch?v=_kn2e-bIlmE) (Spoilers!!),
I (and probably every other nerd) went "ooo! I could make that...". So here it is!

I've never used an Arduino before, so getting everything up and running was a lot of
fun. I learned how easy it can be and now I want to make more projects.

Merry Christmas!

See It In Action!
=================

![](http://i.imgur.com/4oASxrY.jpg)

[Here's an Imgur album of the prototype, the wiring, and some action shots](http://imgur.com/a/isnp1)

Hardware and How To
===================

I used an [Arduino Uno](https://www.amazon.com/gp/product/B008GRTSV6?tag=serve01-20)
to control the project. I used [this power supply](https://www.amazon.com/gp/product/B011QGJ8DG?tag=serve01-20).
And these are the [WS2811 individually addressable lights](https://www.amazon.com/gp/product/B01AG923GI?tag=serve01-20).

You can see [the wiring I did here](http://i.imgur.com/Aye0Iks.jpg). It is very 
simple wiring and the breadboard probably isn't required any more. But it was 
helpful for getting started and trying different things. Basically, you wire
both grounds to the ground on the Arduino, connect the 5V directly to the Arduino 
5V, and connect the data in wire on the lights to one of the data pins on the 
Arduino (pin 3 in my case). That's it!

You can open up the sketchbook in this repository with the Arduino IDE. Then just
tap upload and it should start blinking away if everything is wired correctly! You
may have to select your board and port under Tools -> Board and Tools -> Port,
respectively. 

To customize this, open the sketch in the Arduino IDE. You can change `BLINK_WORD`
to blink any word you want. If you modify `colors`, you can have different colors
picked randomly. You can change `NUM_LEDS` if you are stringing together more light
strips. You can change `DATA_PIN` if your data in wire is not connected to data
pin 3 on the Arduino. When you're done, hit upload, and your lights should start
blinking!

Note: These links are affiliate links.
