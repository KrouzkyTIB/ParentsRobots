import {Component} from "react";
import "../stylesheets/LightsButton.css";


type LightsState = {
    lightsOn: boolean
}

type ButtonProps = {
    lightsChangeHandler: (lightsOn: boolean) => void
}


class LightsButton extends Component<ButtonProps, LightsState> {

    constructor(props: any) {
        super(props);
        this.state = {
            lightsOn: false
        }
    }


    private handleButtonText() {
        return this.state.lightsOn ? "Lights\nON" : "Lights\nOFF"
    }

    private handleClick() {
        this.setState({
            lightsOn: !this.state.lightsOn
        }, () => {
            this.props.lightsChangeHandler(this.state.lightsOn);
        });

    }

    private handleClassChange() {
        return this.state.lightsOn ? "lights-on" : "lights-off";
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