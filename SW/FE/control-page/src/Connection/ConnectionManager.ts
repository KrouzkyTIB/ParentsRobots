import {MoveStats} from "../Components/MovementHandler";
import axios from "axios";
import {ControlData} from "./DataModel/ControlData";

class ConnectionManager {
    private static readonly COMMAND_PATH = "/command";
    static readonly INTERVAL = 500; // interval in millis
    private _leftMotorPower: number;
    private _rightMotorPower: number;
    private _lightsOn: boolean;
    private readonly _intervalID: NodeJS.Timer;
    private static _instance: ConnectionManager | null = null;

    private constructor() {
        this._leftMotorPower = 0;
        this._rightMotorPower = 0;
        this._lightsOn = false;
        this._intervalID = setInterval(this.sendDataToRobot.bind(this), ConnectionManager.INTERVAL);
    }

    public static getInstance(): ConnectionManager {
        if (this._instance === null) {
            this._instance = new ConnectionManager()
        }
        return this._instance
    }


    public refreshPowerSettings(settings: MoveStats) {
        this._leftMotorPower = settings.powerLeft
        this._rightMotorPower = settings.powerRight
    }


    set lightsOn(value: boolean) {
        this._lightsOn = value;
    }

    private async sendDataToRobot() {
        console.log(Math.trunc(this._leftMotorPower), Math.trunc(this._rightMotorPower), this._lightsOn ? "1" : "0")

        const response = await axios.post(
            ConnectionManager.COMMAND_PATH,
            {
                leftMotorPower: Math.trunc(this._leftMotorPower),
                rightMotorPower: Math.trunc(this._rightMotorPower),
                lightsOn: this._lightsOn ? 1 : 0
            },
            {
                url: "http://10.0.0.10", headers: {
                    "Content-Type": "application/json"
                },
                method: "POST"
            }
        )

        console.log(response)
        if (response.status !== 200) {
            throw new Error("Bad request code from source " + response)
        }
    }


    get lightsOn(): boolean {
        return this._lightsOn;
    }

    get intervalID(): NodeJS.Timer {
        return this._intervalID;
    }

    private set leftMotorPower(value: number) {
        this._leftMotorPower = value;
    }

    private set rightMotorPower(value: number) {
        this._rightMotorPower = value;
    }
}

export default ConnectionManager;