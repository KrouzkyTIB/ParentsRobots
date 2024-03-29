import {Joystick} from 'react-joystick-component';
import {Component} from "react";
import {IJoystickUpdateEvent} from "react-joystick-component/build/lib/Joystick";
import "../stylesheets/MovementHandler.css"

type MovementCallback = {
    moveCallback: (state: MoveStats) => void
}

export type MoveStats = {
    x: number
    y: number
    powerLeft: number
    powerRight: number
}


class MovementHandler extends Component<MovementCallback, MoveStats> {
    private readonly MAX_POWER = 100;

    private handleJoystickMovement(event: IJoystickUpdateEvent) {
        this.setState({
            x: event.x!,
            y: event.y!,
            powerLeft: this.calculateLeftMotorPower(event.x!, event.y!, event.distance!),
            powerRight: this.calculateRightMotorPower(event.x!, event.y!, event.distance!)
        }, () => this.props.moveCallback(this.state))

    }

    private calculateLeftMotorPower(x: number, y: number, distance: number): number {
        const xNormalized = x / 0.75;
        const yPower = y < 0 ? Math.sqrt(Math.pow(distance, 2) - Math.pow(xNormalized, 2)) : 0;
        const power = Math.min(Math.abs(xNormalized) + yPower, this.MAX_POWER);
        return x > 0 ? power : -power;
    }

    private calculateRightMotorPower(x: number, y: number, distance: number) {
        const xNormalized = x / 0.75;
        const yPower = y > 0 ? Math.sqrt(Math.pow(distance, 2) - Math.pow(xNormalized, 2)) : 0;
        const power = Math.min(Math.abs(xNormalized) + yPower, this.MAX_POWER);
        return x > 0 ? power : -power;
    }

    handleStop() {
        this.setState({
            x: 0,
            y: 0,
            powerLeft: 0,
            powerRight: 0
        }, () => this.props.moveCallback(this.state))

    }


    render() {
        return (
            <div className="joystick-wrapper">
                <Joystick
                    size={150}
                    sticky={false}
                    baseColor="gray"
                    stickColor="darkgray"
                    move={this.handleJoystickMovement.bind(this)}
                    stop={this.handleStop.bind(this)}
                    followCursor={false}
                ></Joystick>
            </div>
        );
    }
}

export default MovementHandler;