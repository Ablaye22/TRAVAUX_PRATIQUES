#/bin/bash
rm -fr /tmp/.m2 ~/.m2
mkdir /tmp/.m2
ln -s /tmp/.m2 ~/.m2

#Add the proxy configuration to settings.xml default file
SED_OLD="</proxies>"
SED_NEW="<proxy><active>true</active><protocol>https</protocol><host>10.11.10.254</host><port>3128</port></proxy></proxies>"
sed -i -e "s|$SED_OLD|$SED_NEW|g" /etc/maven/settings.xml

echo "=== Maven configuration done ==="
mvn -v

#rm -fr /tmp/.eclipse ~/.eclipse
#mkdir /tmp/.eclipse
#ln -s /tmp/.eclipse ~/.eclipse
#echo ""
#echo "===> You can now start Eclipse from this tab"