#include "simulatedextplaneconnection.h"
#include "simulateddatarefs/simulateddataref.h"
#include "simulateddatarefs/fixedsimulateddataref.h"
#include "simulateddatarefs/alternatingsimulateddataref.h"
#include "../../util/console.h"

SimulatedExtPlaneConnection::SimulatedExtPlaneConnection(QObject *parent) : ExtPlaneConnection(parent) {
    enableSimulatedRefs = true;
}

void SimulatedExtPlaneConnection::connectTo(QString host, unsigned int port) {
    _host = host;
    _port = port;
    server_ok = true;
    emit connectionMessage("Connected to ExtPlane (simulated)");
}

ClientDataRef *SimulatedExtPlaneConnection::createDataRef(QString name, double accuracy) {
    Q_UNUSED(accuracy);
    SimulatedDataRef *simRef = 0;
    if(name=="sim/cockpit2/gauges/indicators/airspeed_kts_pilot") {
        simRef = new SimulatedDataRef(this, 0, 200, 50.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/altitude_ft_pilot") {
        simRef = new SimulatedDataRef(this, 4000, 6000, 50.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/airspeed_acceleration_kts_sec_pilot") {
        simRef = new SimulatedDataRef(this, -40, 40, 5.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/vvi_fpm_pilot") {
        simRef = new SimulatedDataRef(this, -8000, 8000, 5.0, false, 0, name);
    } else if(name=="sim/flightmodel/position/vh_ind") {
        simRef = new SimulatedDataRef(this, -5, 5, 1.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/total_energy_fpm") {
        simRef = new SimulatedDataRef(this, -500, 500, 1.0, false, 0, name);
    } else if(name=="sim/flightmodel/position/latitude") {
        simRef = new SimulatedDataRef(this, 47.3, 47.4, 100.0, false, 0, name);
    } else if(name=="sim/flightmodel/position/longitude") {
        simRef = new SimulatedDataRef(this, 8.5, 8.6, 100.0, false, 0, name);
    } else if(name=="sim/flightmodel/position/local_x") {
        simRef = new SimulatedDataRef(this, 0, 100, 100.0, false, 0, name);
    } else if(name=="sim/flightmodel/position/local_z") {
        simRef = new SimulatedDataRef(this, 0, 100, 100.0, false, 0, name);
    } else if(name=="sim/cockpit/misc/compass_indicated") {
        simRef = new SimulatedDataRef(this, 0, 360, 100.0, true, 0, name);
    } else if(name=="sim/flightmodel/position/hpath") {
        simRef = new SimulatedDataRef(this, -360, 360, 100.0, true, 0, name);
    } else if(name=="sim/flightmodel/misc/h_ind") {
        simRef = new SimulatedDataRef(this, 0, 5000, 10.0, false, 0, name);
    } else if(name=="sim/cockpit/electrical/avionics_on") {
        simRef = new SimulatedDataRef(this, 1, 1, 10.0, true, 0, name);
    } else if(name=="sim/cockpit2/gauges/actuators/barometer_setting_in_hg_pilot") {
        simRef = new SimulatedDataRef(this, 0, 1, 100.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/heading_vacuum_deg_mag_pilot") {
        simRef = new SimulatedDataRef(this, 0, 360, 100.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/heading_electric_deg_mag_pilot") {
        simRef = new SimulatedDataRef(this, 0, 360, 100.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/pitch_vacuum_deg_pilot") {
        simRef = new SimulatedDataRef(this, -90, 90, 5.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/roll_vacuum_deg_pilot") {
        simRef = new SimulatedDataRef(this, -90, 90, 10.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/roll_electric_deg_pilot") {
        simRef = new SimulatedDataRef(this, -30, 30, 10.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/slip_deg") {
        simRef = new SimulatedDataRef(this, -10, 10, 10.0, false, 0, name);
    } else if(name=="sim/cockpit2/gauges/indicators/heading_AHARS_deg_mag_pilot") {
        simRef = new SimulatedDataRef(this, 0, 360, 20.0, false, 0, name);
    } else if(name=="sim/cockpit2/radios/actuators/hsi_obs_deg_mag_pilot") {
        simRef = new SimulatedDataRef(this, 0, 360, 3, false, 0, name);
    } else if(name=="sim/cockpit2/radios/indicators/hsi_hdef_dots_pilot") {
        simRef = new SimulatedDataRef(this, -2.5, 2.5, 10.0, false, 0, name);
    } else if(name=="sim/cockpit2/radios/indicators/hsi_vdef_dots_pilot") {
        simRef = new SimulatedDataRef(this, -2.5, 2.5, 10.0, false, 0, name);
    } else if(name=="sim/cockpit2/autopilot/heading_dial_deg_mag_pilot") {
        simRef = new SimulatedDataRef(this, 0, 360, 3.0, false, 0, name);
    } else if(name=="sim/cockpit2/engine/indicators/engine_speed_rpm") {
        simRef = new SimulatedDataRef(this, 0, 10000, 5.0, false, 4, name);
    } else if(name=="sim/aircraft/view/acf_tailnum") {
        simRef = new AlternatingSimulatedDataRef(this, "EXTPL1,EXTPL2",5.0, name);
    } else if(name=="sim/aircraft/view/acf_descrip") {
        simRef = new FixedSimulatedDataRef(this, "ExtPlane Simulated Connection", name);
    } else if(name=="extplane/navdata/20km") {
        simRef = new NavDataFixedSimulatedDataRef(this, 20000, name);
    } else if(name=="extplane/navdata/100km") {
        simRef = new NavDataFixedSimulatedDataRef(this, 100000, name);
    } else if(name=="sim/flightmodel/controls/parkbrake") {
        simRef = new SimulatedDataRef(this, -1, 1, 1.0, true, 0, name);
    } else if(name=="sim/aircraft/engine/acf_num_engines") {
        simRef = new SimulatedDataRef(this, 1, 4, 20.0, true, 0, name);
    } else if(name=="sim/cockpit2/engine/indicators/N1_percent") {
        simRef = new SimulatedDataRef(this, 0, 100, 10.0, false, 8, name); // X-Plane seems to return 8 engines no matter what
    } else if(name=="sim/cockpit2/engine/indicators/EPR_ratio") {
        simRef = new SimulatedDataRef(this, 1.0, 2.2, 10.0, false, 8, name); // X-Plane seems to return 8 engines no matter what
    } else if(name=="sim/cockpit2/engine/indicators/EGT_deg_C") {
        simRef = new SimulatedDataRef(this, 0.0, 800, 100.0, false, 8, name); // X-Plane seems to return 8 engines no matter what
    } else if(name=="sim/cockpit2/radios/indicators/hsi_display_vertical_pilot") {
        simRef = new SimulatedDataRef(this, 1, 1, 1.0, true, 0, name);
    } else if(name=="sim/cockpit2/radios/indicators/hsi_display_horizontal_pilot") {
        simRef = new SimulatedDataRef(this, 1, 1, 1.0, true, 0, name);
    } else if(name=="sim/cockpit2/radios/indicators/hsi_flag_glideslope_pilot") {
        simRef = new SimulatedDataRef(this, 0, 0, 1.0, true, 0, name);
    } else if(name=="sim/cockpit/autopilot/airspeed") {
        simRef = new SimulatedDataRef(this, 0, 300, 1.0, false, 0, name);
    } else if(name=="sim/cockpit/autopilot/altitude") {
        simRef = new SimulatedDataRef(this, 0, 34000, 34, false, 0, name);
    } else if(name=="sim/cockpit/autopilot/vertical_velocity") {
        simRef = new SimulatedDataRef(this, -2000, 2000, 40, false, 0, name);
    } else if(name=="sim/cockpit/misc/barometer_setting") {
        simRef = new SimulatedDataRef(this, 25.69, 32.06, 100, false, 0, name);
    } else if(name=="sim/physics/metric_press") {
        simRef = new SimulatedDataRef(this, 0, 0, 1.0, true, 0, name);
    } else if(name=="sim/cockpit2/radios/indicators/hsi_dme_distance_nm_pilot") {
        simRef = new SimulatedDataRef(this, 0, 200, 1000, false, 0, name);
    } else if(name=="sim/cockpit2/radios/indicators/hsi_dme_speed_kts_pilot") {
        simRef = new SimulatedDataRef(this, 0, 300, 10, false, 0, name);
    } else if(name=="sim/cockpit/autopilot/autopilot_state") {
        simRef = new SimulatedDataRef(this, -16000, 16000, 1, false, 0, name);
    } else if(name=="sim/cockpit2/radios/actuators/HSI_source_select_pilot") {
        simRef = new SimulatedDataRef(this, 0, 2, 5, true, 0, name);
    } else {
        // Fallback
        INFO << "the dataref " << name << "is not supported by simulation";
        simRef = new SimulatedDataRef(this, -100, 100, 1, false, 0, name);
    }
    simulatedRefs.append(simRef);
    return simRef->clientRef();
}

void SimulatedExtPlaneConnection::unsubscribeDataRef(ClientDataRef *ref) {
    ref->setSubscribers(ref->subscribers() - 1);
    if(ref->subscribers() > 0) return;
    DEBUG << "Ref not subscribed by anyone anymore";
    dataRefs.remove(ref->name());

    foreach(SimulatedDataRef *simRef, simulatedRefs) {
        if(simRef->clientRef()==ref) {
            simRef->deleteLater();
            simulatedRefs.removeOne(simRef);
        }
    }
    disconnect(ref, 0, this, 0);
}

void SimulatedExtPlaneConnection::writeLine(QString line) {
    Q_UNUSED(line);
    //qDebug() << Q_FUNC_INFO << line << "(simulated)";
}

void SimulatedExtPlaneConnection::tickTime(double dt, int total) {
    foreach(SimulatedDataRef *dr, simulatedRefs)
        dr->tickTime(dt, total);
}
