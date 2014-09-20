How to change hostname?
	Edit /etc/sysconfig/network and then reboot

How to change default shell for a specified user?
	chsh -s /bin/csh; use 'man chsh' for more information.

How to add a program to desktop menus in Gnome?
	Create a desktop file to /usr/share/applications for all users, or to ~/.local/share/applications if only for you.
	See https://developer.gnome.org/integration-guide/stable/desktop-files.html.en for details.

How to enable VNC server on CentOS?
	yum install tigervnc
	yum install tigervnc-server
	Edit firewall rules to enable VNC connection:
		firewall-cmd --permanent --zone=public --add-port=5905/tcp
		firewall-cmd --reload

		or configure it through GUI in the Desttop Menus
	vncserver :1 
	vncviewer localhost.localdomain:1
	using 'chkconfig vncserver on' to start vncserver at boot

