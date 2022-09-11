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
        if (y < 0) {
            return x >= 0 ? this.MAX_POWER : -this.MAX_POWER
        }
        const speed: number = Math.sqrt(Math.pow(distance, 2) - Math.pow(y, 2))
        return x >= 0 ? speed : -speed
    }

    private calculateRightMotorPower(x: number, y: number, distance: number) {
        if (y > 0) {
            return x >= 0 ? this.MAX_POWER : -this.MAX_POWER
        }
        const speed: number = Math.sqrt(Math.pow(distance, 2) - Math.pow(y, 2))
        return x >= 0 ? speed : -speed
    }

    private handleStop() {
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