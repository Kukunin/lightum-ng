lightum-ng - Automatic light sensor daemon
===============================================

&copy; 2011-2012 Pau Oliva Fora - pof[at]eslack(.)org
&copy; 2012 Sergey Kukunin - sergey.kukunin[dog]gmail.com

Lightum-ng is the fork of [lightum](https://github.com/poliva/lightum) porject.

Lightum-ng is a daemon to control the keyboard and screen backlight, screen temperature on computer based on several inputs: light sensors, webcam or position of the sun.

Original lightum project is aimed only on Macbook notebooks, has only several backends and has hard to extend architecture (IMHO).
It works fine on the Macbook with Gnome or KDE environments. You can use it now.

Lightum-ng is aimed to support more platforms, operation systems, sensors and backends. It will have the easy to extend architecture, written on C++ with minimum dependencies (Only plugins will have some specific dependencies. You will able to compile it with various set of plugins).

Features
-------------------
Daemon will be able to autocontrol the

- screen backlight
- keyboard brightness
- screen temperature

based on the different inputs

- light sensors
- webcam
- position of the sun

Also, daemon will dim the screen and keyboard backlight when user is inactive.


Development
-------------------

Development was started 31st of October, 2012. There isn't working version, only short briefing about the future project.

Feel free to contribute your bugreports, pull requests, code reviews, advices etc. It's collaborative project.

[<img src="http://api.flattr.com/button/flattr-badge-large.png" alt="Flattr this" title="Flattr this" border="0" />](http://flattr.com/thing/970527/Kukuninlightum-ng-on-GitHub)
