import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID

DEPENDENCIES = ['uart']

scservo_ns = cg.esphome_ns.namespace('scservo')
SCBusServo = scservo_ns.class_('SCBusServo', cg.Component, uart.UARTDevice)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(SCBusServo),
    cv.Required(uart.CONF_UART_ID): cv.use_id(uart.UARTComponent),
    cv.Optional('servo_id', default=1): cv.int_range(min=1, max=254),
    cv.Optional('min_angle', default=0.0): cv.float_,
    cv.Optional('max_angle', default=180.0): cv.float_,
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
    cg.add(var.set_servo_id(config['servo_id']))
    cg.add(var.set_min_angle(config['min_angle']))
    cg.add(var.set_max_angle(config['max_angle']))
