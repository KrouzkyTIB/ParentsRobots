import {Component} from "react";
import "../stylesheets/LightsButton.css";

enum LightsStatus {
    ON = 1,
    OFF = 0
}

type LightsState = {
    turnOn: LightsStatus
}

type ButtonProps = {
    lightsChangeHandler: (status: LightsState) => void
}


class LightsButton extends Component<ButtonProps, LightsState> {

    constructor(props: any) {
        super(props);
        this.state = {
            turnOn: LightsStatus.OFF
        }
        console.debug("constructor", this.state.turnOn)
    }


    private handleButtonText() {
        if (this.state.turnOn === LightsStatus.ON) {
            return "Lights\nON"
        }
        return "Lights\nOFF"
    }

    private handleClick() {
        if (this.state.turnOn === LightsStatus.ON) {
            this.setState({
                turnOn: LightsStatus.OFF
            })
        } else {
            this.setState(
                {
                    turnOn: LightsStatus.ON
                }
            )
        }
        this.props.lightsChangeHandler(this.state)
    }

    private handleClassChange() {
        if (this.state.turnOn === LightsStatus.ON) {
            return "lights-on"
        }
        return "lights-off"
    }

    render() {
        return (
            <button
                className={"lights-button " + this.handleClassChange()}
                onClick={this.handleClick.bind(this)}>
                {this.handleButtonText()}
            </button>
        );
    }
}

export default LightsButton;