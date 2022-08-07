import {MoveStats} from "../Components/MovementHandler";
import axios from "axios";
import {ControlData} from "./DataModel/ControlData";

class ConnectionManager {
    private readonly IP_ADDRESS = "10.0.0.10";
    private readonly MAX_RETIRES = 10;
    private _leftMotorPower: number;
    private _rightMotorPower: number;
    private _lightsOn: boolean;

    constructor() {
        this._leftMotorPower = 0;
        this._rightMotorPower = 0;
        this._lightsOn = false;

    }

    public refreshPowerSettings(settings: MoveStats) {
        this._leftMotorPower = settings.powerLeft
        this._rightMotorPower = settings.powerRight
    }

    public refreshLightsStatus(lightsOn: boolean) {
        this._lightsOn = lightsOn
    }

    private async sendDataToRobot() {
        const response = await axios.post(
            this.IP_ADDRESS,
            JSON.stringify(new ControlData(this._leftMotorPower, this._rightMotorPower, this._lightsOn))
        )
        console.debug(response)
    }


}

export default ConnectionManager;