#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto lpp = getValue<input_LPP>(ctx);
        lpp->addGPS(
            getValue<input_CHL>(ctx),
            getValue<input_Lat>(ctx),
            getValue<input_Long>(ctx),
            getValue<input_Alt>(ctx));
        emitValue<output_Done>(ctx, 1);
    }
}
