/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * opendmxdevice.cpp
 * Art-Net device
 * Copyright (C) 2005  Simon Newton
 *
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "opendmxdevice.h"
#include "opendmxport.h"


/*
 * Create a new device
 *
 * should prob pass the ip to bind to
 *
 */
OpenDmxDevice::OpenDmxDevice(Plugin *owner) : Device(owner) {
	m_enabled = false ;
}


/*
 *
 */
OpenDmxDevice::~OpenDmxDevice() {
	if (m_enabled)
		stop() ;
}


/*
 * Start this device
 *
 */
int OpenDmxDevice::start() {
	OpenDmxPort *port ;

	port = new OpenDmxPort(this,0) ;

	if(port != NULL) 
		this->add_port(port) ;

	m_enabled = true ;

	return 0;
}


/*
 * stop this device
 *
 */
int OpenDmxDevice::stop() {
	Port *prt ;

	if (!m_enabled)
		return 0 ;

	for(int i=0; i < get_ports() ; i++) {
		prt = get_port(i) ;
		if(prt != NULL)
			delete prt ;
	}

	m_enabled = false ;
	return 0;
}



// call this when something changes
// where to store data to ?
// I'm thinking a config file in /etc/llad/llad.conf
int OpenDmxDevice::save_config() {


	return 0;
}



/*
 * we can pass plugin specific messages here
 * make sure the user app knows the format though...
 *
 */
int OpenDmxDevice::configure(void *req, int len) {
	// handle short/ long name & subnet and port addresses
	
	req = 0 ;
	len = 0;

	return 0;
}





// Private functions
//-----------------------------------------------------------------------------





