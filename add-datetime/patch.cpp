#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto lpp = getValue<input_LPP>(ctx);
        lpp->addUnixTime(
            getValue<input_CHL>(ctx),
            getValue<input_DT>(ctx));
        emitValue<output_Done>(ctx, 1);
    }
}
