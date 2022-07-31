import ReactSlider from "react-slider";
import React from "react";

const MAX_SLIDER_VAL = 100
const MIN_SLIDER_VAL = -100
const DEFAULT_SLIDER_VAL = 0


export const enum Position {
    RIGHT = "right",
    LEFT = "left"
}

type SpeedSliderProps = {
    refreshCallback: (value: number) => void
    position: Position
}

type SpeedSliderState = {
    value: number
}

class Slider extends React.Component<SpeedSliderProps, SpeedSliderState> {


    readonly state: SpeedSliderState = {
        value: DEFAULT_SLIDER_VAL
    }

    private valueChangeHandler(value: number) {
        this.setState({
            value: value
        })
        this.props.refreshCallback(value)
    }

    private resetToMiddle() {
        this.setState({
            value: DEFAULT_SLIDER_VAL
        })
        this.props.refreshCallback(DEFAULT_SLIDER_VAL)
    }

    render() {
        return (
            <div className={"sliderDiv " + this.props.position.valueOf()}>
                <ReactSlider
                    className={"speedSlider " + this.props.position.valueOf()}
                    trackClassName="speedSliderTrack"
                    max={MAX_SLIDER_VAL}
                    min={MIN_SLIDER_VAL}
                    defaultValue={DEFAULT_SLIDER_VAL}
                    thumbClassName="speedSliderThumb"
                    onChange={value => {
                        this.valueChangeHandler(value)
                    }}
                    onAfterChange={() => {
                        this.resetToMiddle()
                    }}
                    value={this.state.value}
                    orientation="vertical"
                />
            </div>
        )
    }
}

export default Slider;
